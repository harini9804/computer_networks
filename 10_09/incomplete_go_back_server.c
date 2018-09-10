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

  int n, window_size;
  int current_packet =0;


    printf("\nEnter window_size: ");
    scanf("%d",&window_size);
    //send window size to client
    send(client_socket, &window_size, sizeof(window_size), 0);

  printf("\nEnter the number of packets you want to send");
  scanf("%d",&n);
  char a[n][256];
  gets(a[0]);
  for(int i=0;i<n;i++){
    printf("\nEnter packet %d",i);
    gets(a[i]);
  }

  char response[256], message[256];

    strcpy(message," Initiated ");

    printf("\nSession initiated.");

  for(int i=0;i<window_size;i++){
    send(client_socket, &a[i], sizeof(a[i]), 0);
  }
  current_packet=window_size;


    while(current_packet <n)
    {
      //Receiving from client
      recv(client_socket, &response, sizeof(response), 0 );
      if(!strcmp(response,"ack.")){
        printf("\nClient:");
        puts(response);
      }


      if(!strcmp(response,"$"))
        break;
      printf("\nYou: ");
      gets(message);
    }

  close(server_socket);

  return 0;
}
