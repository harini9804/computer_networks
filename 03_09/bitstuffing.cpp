#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;
string esc_at_occurrence(string str, string flagchk, string esc);
string esc_at_occurrence(string str, string flagchk, string esc){

  vector<int> occ_pos;
  int pos = str.find(flagchk);

  while(pos!=string::npos){
    occ_pos.push_back(pos);
    pos+=flagchk.length();
    str.insert(pos,esc);
    pos = str.find(flagchk,pos);

  }

  for(auto it=occ_pos.begin();it!=occ_pos.end();it++){
    cout<<*it<<endl;
  }

  return str;
}
int main(){

  string str,flag="01111110";
  string flagchk="011111";
  string esc="0";
  vector<string> frames;
  int n;
  cout<<"\nEnter number of packets: ";
  cin>>n;
  int pos;
  for(int i=0;i<n;i++){
    cout<<"\nEnter packet: ";
    cin>>str;
    str = esc_at_occurrence(str,flagchk,esc);
    str.insert(0,flag+" ");
    str = str+" "+flag;
    frames.push_back(str);
  }

  cout<<"\nThe packets are: ";
  for(auto it=frames.begin();it!=frames.end();it++){
    cout<<*it<<endl;
  }
  return 0;


  return 0;
}
