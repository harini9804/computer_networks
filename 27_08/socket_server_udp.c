#include <stdio.h>
#include <stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

int main(){

  //create a socket
  int server_socket = socket(AF_INET, SOCK_DGRAM, 0);

  struct sockaddr_in server_address,client_address; // from netinet/in.h
  socklen_t addr_size;

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(3000);
  server_address.sin_addr.s_addr = INADDR_ANY;

  if(bind(server_socket,(struct sockaddr *)&server_address, sizeof(struct sockaddr)) == 0 ){
    printf("\nBinding done!\n");
  }
  else{
    printf("\nBind error.");
  }

  char echomesg[256],request_msg[256];
  addr_size=sizeof(client_address);
  //Receiving message from client
  recvfrom(server_socket, request_msg, sizeof(request_msg), 0, (struct sockaddr *)&client_address, &addr_size);
  //Display the message
  printf("\nMessage from client: %s", request_msg);
  //Getting message from user
  printf("\nEnter message for client: ");
  gets(echomesg);

  printf("\nSending message to client..");

  //Sending to client
  sendto(server_socket, echomesg, sizeof(echomesg), 0, (struct sockaddr *)&client_address, addr_size);
  printf("\nDone!");


  close(server_socket);

  return 0;
}
