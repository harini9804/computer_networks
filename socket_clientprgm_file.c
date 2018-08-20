#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

#include <string.h>

int main(){

  int client_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(3000);
  server_address.sin_addr.s_addr = INADDR_ANY;

  if(connect(client_socket,(struct sockaddr *)&server_address, sizeof(server_address)) == 0){
    printf("\nConnection successful.\n");
  }
  else{
    printf("\nConnection failed.");
  }

  char message[80];
  strcpy(message," ");

  FILE *fp;
  fp = fopen("client_file.txt","w");

  while(strcmp(message,"$") ){

    recv(client_socket, &message, sizeof(message), 0);
    fwrite(message, sizeof(message), 1, fp);
    puts(message);

}

  close(client_socket);
  return 0;
}
