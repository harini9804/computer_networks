#include <stdio.h>
#include <stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>
#include<string.h>

int main(){

  //create a socket
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address; // from netinet/in.h
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(3000);
  server_address.sin_addr.s_addr = INADDR_ANY;

  if( connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address) ) == 0 ){
    printf("\nConnection successful.");
  }
  else{
    printf("\nConnection failed.");
    return -1;
  }

char response[256], message[256];

strcpy(message," ");

  printf("\nChat session initiated. Enter '$' to terminate.");

  while(strcmp(message,"$"))
  {

    //Receiving from server
      recv(client_socket, &response, sizeof(response), 0 );
      printf("\nServer: ");
      puts(response);

      if(!strcmp(response,"$"))
        break;

      printf("\nYou (ack/nack): ");
      gets(message);

      //Sending message to server
      send(client_socket, &message, sizeof(message), 0);
  }

  close(client_socket);

  return 0;
}
