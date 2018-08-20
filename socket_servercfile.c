#include <stdio.h>
#include <stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>
#include <unistd.h>

#include<string.h>

int main(){

  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(3000);
  server_address.sin_addr.s_addr = INADDR_ANY;

  if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(struct sockaddr)) == 0){
    printf("\nBinding done!");
  }
  else{
    printf("\nBind error.");
  }

  listen(server_socket,3);

  int client_socket = accept(server_socket, NULL, NULL);

  char str_file[80], message[80];
  strcpy(message,"$");
  FILE *fp;

  fp = fopen("socket_clientprgm_echo.c","r");

  if(!fp){
    printf("\nError in opening file");
  }

  while(fread(str_file, sizeof(str_file),1, fp) == 1){

    send(client_socket, &str_file, sizeof(str_file), 0);
  }

  send(client_socket, &message, sizeof(message), 0);

  fclose(fp);

  return 0;
}
