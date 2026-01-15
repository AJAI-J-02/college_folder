#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080
#define MAX_BUF_LEN 1024
int main() {
int sockfd;
struct sockaddr_in server_addr;
char buffer[MAX_BUF_LEN];

if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
perror("Socket failed");
exit(1);
}

memset(&server_addr, 0, sizeof(server_addr));
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(PORT);
server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

printf("Enter message: ");
fgets(buffer, sizeof(buffer), stdin);
buffer[strcspn(buffer, "\n")] = 0; 
sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
ssize_t n = recvfrom(sockfd, buffer, MAX_BUF_LEN, 0, NULL, NULL);
buffer[n] = '\0';
printf("Server response: %s\n", buffer);
close(sockfd);
return 0;
}
