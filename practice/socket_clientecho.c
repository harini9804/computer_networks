#include<stdlib.h>
#include<stdio.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<unistd.h>
#include<netinet/in.h>

int main(){

  int client_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(3000);
  server_address.sin_addr.s_addr = INADDR_ANY;

  if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == 0){
    printf("\nConnection successful");
  }
  else{
    printf("\nError");
    return -1;
  }

  char message[256];
  recv(client_socket,&message, sizeof(message),0);
  printf("\nMessage from server: %s ",message );
  send(client_socket, &message,sizeof(message),0);
  printf("\nSent the message back.");

  close(client_socket);

return 0;
}
