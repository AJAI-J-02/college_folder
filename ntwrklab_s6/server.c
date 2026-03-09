#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080
#define MAX_BUF_LEN 1024
int main() {
int sockfd;
struct sockaddr_in server_addr, client_addr;
socklen_t len = sizeof(client_addr);
char buffer[MAX_BUF_LEN];

if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
perror("Socket failed");
exit(1);
}

memset(&server_addr, 0, sizeof(server_addr));
server_addr.sin_family = AF_INET;
server_addr.sin_addr.s_addr = INADDR_ANY;
server_addr.sin_port = htons(PORT);

if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
perror("Bind failed");
exit(1);
}
printf("Server listening on port %d...\n", PORT);
while (1) {
ssize_t n = recvfrom(sockfd, buffer, MAX_BUF_LEN, 0, (struct sockaddr *)&client_addr,
&len);
buffer[n] = '\0'; 
printf("Received: %s\n", buffer);
sendto(sockfd, "Message received", 17, 0, (struct sockaddr *)&client_addr, len);
}
close(sockfd);
return 0;
}
