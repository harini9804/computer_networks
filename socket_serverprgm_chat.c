#include <stdio.h>
#include <stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

#include <string.h>

int main(){

  //create a socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address; // from netinet/in.h
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(3000);
  server_address.sin_addr.s_addr = INADDR_ANY;

  if(bind(server_socket,(struct sockaddr *)&server_address, sizeof(struct sockaddr)) == 0 ){
    printf("\nBinding done!\n");
  }
  else{
    printf("\nBind error.");
  }

  listen(server_socket, 3);


  int client_socket = accept( server_socket, NULL, NULL);

  char response[256], message[256];

    strcpy(message," Initiated ");

    printf("\nChat session initiated. Enter '$' to terminate.");

    while(strcmp(message,"$"))
    {

      //Sending message to client
      send(client_socket, &message, sizeof(message), 0);

      //Receiving from client
      recv(client_socket, &response, sizeof(response), 0 );
      printf("\nClient:");
      puts(response);

      if(!strcmp(response,"$"))
        break;
      printf("\nYou: ");
      gets(message);
    }

  close(server_socket);

  return 0;
}
