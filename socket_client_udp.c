#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

int main(){

  //create a socket
  int client_socket = socket(AF_INET, SOCK_DGRAM, 0);

  socklen_t addr_size;

  struct sockaddr_in server_address; // from netinet/in.h
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(3000);
  server_address.sin_addr.s_addr = INADDR_ANY;

  addr_size=sizeof(server_address);
  char response[256], request[256];

  printf("\nEnter message for server: ");
  gets(response);

  //Sending the message back to server
  printf("\nSending message to server..");
  sendto(client_socket, response, sizeof(response), 0, (struct sockaddr *)&server_address, sizeof(server_address));
  printf("\nDone!");
  //Receiving from server
  printf("\nReceiving message from server..");
  recvfrom(client_socket, response, sizeof(response), 0, (struct sockaddr *)&server_address,&addr_size );
  printf("\nMessage from server: %s \n", response);



  close(client_socket);

  return 0;
}
