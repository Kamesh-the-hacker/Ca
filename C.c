 #include<stdio.h>
#include<string.h>
 #include<sys/socket.h>
 #include<netinet.h>
 #include<arpa/inet.h>
 #include <unistd.h>
int main()
 {
 int s;
 char msg[100] = "Hello Server";
 struct sockaddr_in server;
 s = socket(AF_INET, SOCK_STREAM, 0);
 server.sin_family = AF_INET;
 server.sin_port = htons(9001); 
server.sin_addr.s_addr = inet_addr("127.0.0.1");
 connect(s, (struct sockaddr*)&server, sizeof(server));
 send(s, msg, sizeof(msg), 0); 
recv(s, msg, sizeof(msg), 0);
 printf("Server: %s\n", msg); 
return 0;
 }
