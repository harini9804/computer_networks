#include <stdio.h>
#include <stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

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

  char echomesg[256],request_msg[256];

  //Getting message from user
  printf("\nEnter message for client: ");
  gets(echomesg);

  printf("\nSending message to client..");
  //Sending to client
  send(client_socket, echomesg, sizeof(echomesg), 0);
  printf("\nDone!");

  //Receiving message from client
  recv(client_socket, &request_msg, sizeof(request_msg), 0);

  //Display the message
  printf("\nMessage from client: %s", request_msg);

  close(server_socket);

  return 0;
}
