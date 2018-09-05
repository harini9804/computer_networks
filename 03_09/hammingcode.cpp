#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{

  int n,k=1,ntot;
  int pos;
  // cout<<"\nEnter number of data bits: ";
  // cin>>n;
   int a[8],atemp[8],err[3];
  cout<<"\nEnter four data bits: ";
  cin>>a[3]>>a[5]>>a[6]>>a[7];
  a[1]=a[3]^a[5]^a[7];
  a[2]=a[3]^a[6]^a[7];
  a[4]=a[5]^a[6]^a[7];
  // while( ( pow(2,k)<(n+k+1) ) ){
  //   k++;
  // }
  // ntot = n+k;
  printf("\nData sent: ");
  for(int i=1;i<=7;i++){
    printf("%d ",a[i]);
  }

  printf("\nEnter data received: ");
  for(int i=1;i<=7;i++){
    cin>>atemp[i];
  }
  err[2]=atemp[1]^atemp[3]^atemp[5]^atemp[7];
  err[1]=atemp[2]^atemp[3]^atemp[6]^atemp[7];
  err[0]=atemp[4]^atemp[5]^atemp[6]^atemp[7];

  cout<<err[0]<<err[1]<<err[2];                                     
  if((err[0]+err[1]+err[2]) == 0)
  {
    printf("\nNo error.");
  }
  else
  {
    pos = 4*err[0]+2*err[1]+err[2];
    printf("\nBit error at position %d", pos);
    printf("\nCorrecting error..");

    atemp[pos]= atemp[pos]^1; // inverting bit;

    printf("\nCorrected data: ");
    for(int i=1;i<=7;i++)
      printf("%d ",atemp[i]);

  }
  return 0;
}
