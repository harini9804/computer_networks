#include<stdlib.h>
#include<stdio.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>
#include<unistd.h>

int main(){

int server_socket = socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in server_address;
server_address.sin_family = AF_INET;
server_address.sin_port = htons(3000);
server_address.sin_addr.s_addr = INADDR_ANY;

if(bind(server_socket,(struct sockaddr *)&server_address, sizeof(server_address))==0){
  printf("\nBind successful.");
}
else{
  printf("\nBinding unsuccessful");
}

listen(server_socket,3);

int client_socket = accept(server_socket, NULL, NULL);

char message[256];
printf("\nEnter your message for the client ");
gets(message);

send(client_socket,&message, sizeof(message), 0);
recv(client_socket, &message, sizeof(message), 0);
printf("\nMessage from the client: %s",message );

close(server_socket);


return 0;
}
