#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

int main()
{
  string str;
  vector<string> frames;
  int n;

  printf("\nEnter number of packets: ");
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>str;
    frames.push_back(str);
  }
  cout<<"\nPackets: ";
  for(auto it=frames.begin();it!=frames.end();it++){
    cout<<(*it).size()+1<<*it<<' ';
  }

  return 0;
}
