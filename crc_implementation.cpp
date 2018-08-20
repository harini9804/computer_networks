#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int bitxor(int &a, int &b){
  if(a==b){
    a=0;
    return 0;
  }


  return 1;
}
vector<int> calc_remainder(vector<int> data, vector<int> key);
vector<int> calc_remainder(vector<int> data, vector<int> key){

  vector<int> pp;
  int n_key = key.size();
  pp.assign(data.begin(),data.begin()+n_key);

  auto id = data.begin()+n_key;
  while(id!=data.end()){
    transform(pp.begin(),pp.end(),key.begin(),pp.begin(),bitxor);
    while(pp.front()==0){
      pp.erase(pp.begin());
      pp.push_back(*id);
      id++;
      if(id==data.end())
      break;
    }
  }
  if(pp.size()!=key.size()){
    cout<<"\nRemainder: ";
    for(auto it=pp.begin();it!=pp.end();it++){
      cout<<*it;
    }
    return pp;
  }
  transform(pp.begin(),pp.end(),key.begin(),pp.begin(),bitxor);

  cout<<"\nRemainder: ";
  for(auto it=pp.begin();it!=pp.end();it++){
    cout<<*it;
  }
  return pp;

}
int main(){

  int n_data,n_key;
  int n_databef;
  cout<<"\nEnter the number of key bits: ";
  cin>>n_key;
  vector<int> key;
  vector<int> pp;
  int ele;
  cout<<"\nEnter the key: ";
  for(int i=0;i<n_key;i++){
    cin>>ele;
    key.push_back(ele);
  }
  cout<<"\nkey:";
  for(auto it=key.begin();it!=key.end();it++){
    cout<<*it;
  }
  cout<<"\nEnter the number of data bits: ";
  cin>>n_data;
  n_databef = n_data;
  vector<int> data;

  cout<<"\nEnter the data: ";
  for(int i=0; i<n_data;i++){
    cin>>ele;
    data.push_back(ele);
  }
  for(int i = 0;i<n_key-1;i++){
    data.push_back(0);
  }
  cout<<"\ndata:";
  for(auto it=data.begin();it!=data.end();it++){
    cout<<*it;
  }
  cout<<"\nInputs done.";

  pp=calc_remainder(data,key);

  int x;
  n_data = data.size();
  vector<int> data1;
  data1.resize(data.size());
  data1.assign(data.begin(),data.begin()+n_databef);
  for(int i=1;i<=n_key-1;i++){
    data1.push_back(pp[i]);
  }
  cout<<"\ndata1: ";
  for(auto it=data1.begin();it!=data1.end();it++){
    cout<<*it;
  }
  int data1_size = data1.size();
  cout<<"\n1.Send correct data.\n2.Modify a data bit";
  cin>>x;
  switch (x) {
    case 2: int bitno;
            cout<<"\nEnter bit number ( 0 to "<<data1_size-1<<" ): ";
            cin>>bitno;
            if(bitno>=data1_size){
              cout<<"\nIncorrect.";
              break;
            }
            else{
              if(data1[bitno])
                data1[bitno]=0;
              else
                data1[bitno]=1;
            }
            cout<<"\nData sent: ";
            for(auto it=data1.begin();it!=data1.end();it++){
              cout<<*it;
            }
            pp=calc_remainder(data1,key);
            break;

    default: cout<<"\nSending correct data: ";
              cout<<"\nData sent: ";
              for(auto it=data1.begin();it!=data1.end();it++){
                cout<<*it;
              }
            pp=calc_remainder(data1,key);
  }
  return 0;
}
