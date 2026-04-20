#include<stdio.h> 
#include<string.h>
 #include<sys/socket.h>
 #include<netinet/in.h>
 #include<unistd.h>
 int main()
{
int s, c;
 char msg[100];
 struct sockaddr_in server;
 s = socket(AF_INET, SOCK_STREAM, 0);
 server.sin_family = AF_INET; 
server.sin_port = htons(9001);
 server.sin_addr.s_addr = INADDR_ANY; 
bind(s, (struct sockaddr*)&server, sizeof(server));
 listen(s, 1);
 c = accept(s, NULL, NULL);
 recv(c, msg, sizeof(msg), 0); 
printf("Client: %s\n", msg);
 strcpy(msg, "Hello Client");
 send(c, msg, sizeof(msg), 0); 
return 0; 
} 
