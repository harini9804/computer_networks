
#include<stdio.h>

int main(){

  int n;
  printf("\nEnter the number of packets: ");
  scanf("%d",&n);

  int a[n],b[n],window_size;

  for(int i=0;i<n;i++){
    printf("\nEnter bit no %d: ",i );
      scanf("%d",&a[i]);
  }
  printf("\nEnter window size: ");
  scanf("%d",&window_size);

  int current_packet=0,ack;
  for(int i=0;i<window_size;i++){
    printf("\nSent %d: %d",current_packet,a[current_packet]);
    current_packet++;
  }
  while(current_packet<n)
  {
    printf("\nSend acknowledgement as: ");
    scanf("%d",&ack);
    if(ack==current_packet){
      printf("Sent %d: %d",current_packet,a[current_packet]);
      current_packet++;
    }
    else{
      current_packet = ack - window_size + 1;
      if(current_packet<0){
        current_packet = 0;
      }
      if(current_packet+window_size<n)
      {
        for(int i=0; i<window_size;i++){
          printf("\nSent %d: %d",current_packet,a[current_packet]);
          current_packet++;
        }
      }
      else{
          while(current_packet<n){
            printf("\nSent %d: %d",current_packet,a[current_packet]);
            current_packet++;
          }
        }
      }

    }


  return 0;
}
