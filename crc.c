#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
int main(){

  int n_data,n_key;
  int xor
  cout<<"\nEnter the number of key bits";
  cin>>n_key;
  vector<int> key(n_key);
  vector<int> pp(n_key);
  int ele;
  for(int i=0;i<n_key;i++){
      cin>>ele;
      key.push_back(ele);
  }
  cout<<"\nEnter the number of data bits";
  cin>>n_data;
  n_data+=3;
  vector<int> data(n_data);
  cout<<"\nEnter the data";
  for(int i=0;i<n_data-n_key-1;i++){
    cin>>ele;
    data.push_back(ele);
  }
  vector<int>::iterator it_d,it_p;

  for(int i = n_data - n_key -1;i<n_data;i++){
    data[i] = 0;
  }
  pp.assign(data.begin(),data.begin()+n_key);
  it_d = data.begin()+n_key;
  while(it_d!= data.end()+1)
  {
    transform(pp.begin(),pp.end(),key.begin(),pp.begin(),[](const int &a, const int &b){return a^b;});
    while(pp.front()==0){
      pp.erase(pp.begin());
      pp.push_back(*it_d);
      it_d++;
    }
  }

  for(it_p= pp.begin(); it_p! = pp.end();it_d++){
    cout<<*it_p;
  }



  return 0;
}
