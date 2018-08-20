#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main(){

  int n_data,n_key;
  int n_databef;
  cout<<"\nEnter the number of key bits";
  cin>>n_key;
  int key[n_key];
  int pp[n_key];
  int ele;
  for(int i=0;i<n_key;i++){
      cin>>key[i];
  }
  cout<<"\nEnter the number of data bits";
  cin>>n_data;
  vector<int> data;

  cout<<"\nEnter the data";
  for(int i=0; i<n_data;i++){
    cin>>ele;
    data.push_back(ele);
  }
  cout<<"\nInputs done.";

  vector<int>::iterator it_d,it_p,it_k;

  for(int i = 0;i<n_key-1;i++){
    data.push_back(0);
  }

  n_databef= n_data;
  n_data = data.size();
  for(int i=0;i<n_key;i++){
    pp[i]=data[i];
  }
  it_d = data.begin()+n_key;

  int id = n_key;
  int flag=0;
  while(id<n_data)
  {
  // transform(pp.begin(),pp.end(),key.begin(),pp.begin(),[](const int &a, const int &b){if(a==b)return 0; return 1;});
    for(int i =0; i<n_key;i++)
    {
      if(key[i] == pp[i])
        {
          pp[i]=0;
          cout<<"made 0";
              }
      else
      pp[i] = 1;
    }

    for(int i =0; i<n_key;i++){
      cout<<pp[i];
    }

    while(pp[0]==0){

      for(int i = 0 ; i<n_key-1; i++){
        pp[i]=pp[i+1];
      }
      pp[n_key-1] =data[id];
      id++;
      flag = 1;
      cout<<"run";
    }
    if(!flag)
    return 0;
    cout<<"\npp now";
    for(int i =0; i<n_key;i++){
      cout<<pp[i];
    }
 cout<<'\n';

  }
// transform(pp.begin(),pp.end(),key.begin(),pp.begin(),[](const int &a, const int &b){ if(a==b)return 0; return 1;});
 for(int i =0; i<n_key;i++){
   if(key[i] == pp[i])
     {
       pp[i] =0;
       cout<<"made 0";
     }
   else
   pp[i] = 1;
 }
 cout<<"\nfinal pp:";
 for(int i =0; i<n_key;i++){
   cout<<pp[i];
 }
 cout<<"\n\n";
//---------------------------------------//
int data1[n_data];

for(int i=0;i<n_databef;i++){
  data1[i]=data[i];
}
int k=1;
for(int i=n_databef;i<n_data;i++){
  data1[i]=pp[k];
  cout<<pp[k];
  k++;
}
cout<<"\nNew dividend";
for(int i=0;i<n_data;i++){
  cout<<data1[i];
}
cout<<'\n';
for(int i=0;i<n_key;i++){
  pp[i]=data1[i];
}
//it_d = data.begin()+n_key;

 id = n_key;
 flag=0;
while(id<n_data)
{
// transform(pp.begin(),pp.end(),key.begin(),pp.begin(),[](const int &a, const int &b){if(a==b)return 0; return 1;});
    for(int i=0; i<n_key;i++){
    if(key[i] == pp[i])
      {
        pp[i]=0;
      }
    else
    pp[i] = 1;
    }

    for(int i =0; i<n_key;i++){
      cout<<pp[i];
    }

  while(pp[0]==0){

    for(int i = 0 ; i<n_key-1; i++){
      pp[i]=pp[i+1];
    }
    pp[n_key-1] =data1[id];

    id++;
    flag = 1;
  }
  if(!flag)
  return 0;
  cout<<"\npp now";
  for(int i =0; i<n_key;i++){
    cout<<pp[i];
  }
cout<<'\n';

}
// transform(pp.begin(),pp.end(),key.begin(),pp.begin(),[](const int &a, const int &b){ if(a==b)return 0; return 1;});
for(int i =0; i<n_key;i++){
 if(key[i] == pp[i])
   {
     pp[i] =0;
     cout<<"made 0";
   }
 else
 pp[i] = 1;
}
cout<<"\nfinal pp now!:";
for(int i =0; i<n_key;i++){
 cout<<pp[i];
}

  return 0;
}
