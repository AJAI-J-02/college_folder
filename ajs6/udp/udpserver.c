

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;           
    server_addr.sin_addr.s_addr = INADDR_ANY;   
    server_addr.sin_port = htons(SERVER_PORT);  

    
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("UDP Server listening on port %d...\n", SERVER_PORT);

    while (1) {
        
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_addr_len);
        if (n < 0) {
            perror("Receive failed");
            continue;
        }
        
        
        if (strcmp(buffer, "exit") == 0) {
            printf("Exiting client...\n");
            break;
        }
        
        buffer[n] = '\0';  
        printf("Received from client: %s\n", buffer);

  
        char response[BUFFER_SIZE];
        printf("Enter message: ");
        fgets(response, BUFFER_SIZE, stdin);
        response[strcspn(response, "\n")] = 0;  
        sendto(sockfd, response, strlen(response), 0, (struct sockaddr *)&client_addr, client_addr_len);
    }

    close(sockfd);
    return 0;
}


