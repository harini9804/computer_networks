#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;
string esc_at_occurrence(string str, string bytestuff, string dle);
string esc_at_occurrence(string str, string bytestuff, string dle){

  vector<int> occ_pos;
  int pos = str.find(bytestuff);

  while(pos!=string::npos){

    str.insert(pos,dle);
    occ_pos.push_back(pos);
    pos+=bytestuff.length()+dle.length();
    pos = str.find(bytestuff,pos);

  }

  for(auto it=occ_pos.begin();it!=occ_pos.end();it++){
    cout<<*it<<endl;
  }

  return str;
}

int main(){

  string str,dle,stx,etx;
  string bytestuff,endstuff;
  vector<string> frames;
  int n;
  cout<<"\nEnter number of packets: ";
  cin>>n;
  cout<<"\nEnter DLE: ";
  cin>>dle;
  cout<<"\nEnter STX: ";
  cin>>stx;
  cout<<"\nEnter ETX: ";
  cin>>etx;
  bytestuff = dle+stx;
  endstuff = dle+etx;
  for(int i=0;i<n;i++){
    cout<<"\nEnter packet: ";
    cin>>str;
    str = esc_at_occurrence(str,bytestuff,dle);
    str.insert(0,bytestuff+" ");
    str.append(" "+endstuff);
    frames.push_back(str);
  }
  cout<<"\nFrames: ";
  for(auto it = frames.begin();it!=frames.end();it++){
    cout<<*it<<'\n';
  }


  return 0;
}
