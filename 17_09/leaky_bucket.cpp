#include<iostream>
#include<queue>

using namespace std;

int no_of_ele=0, bucket_size=0;

queue<int> bucket_enter(queue<int> bucket, int input_rate){
  for(int i=0;i<input_rate;i++){

    if(no_of_ele==bucket_size){
      cout<<"\nBucket full!"<<endl;
      break;
    }
    bucket.push(1);
    no_of_ele++;
  }
  return bucket;
}

queue<int> bucket_exit(queue<int> bucket, int trans_rate){
  int count=0;
  if(bucket.empty()){
    cout<<"\nBucket is empty!";
    return bucket;
  }
  else{
    while(!bucket.empty()){
      bucket.pop();
      no_of_ele--;
      count++;

      if(count == trans_rate){
        break;
      }
    }
  }

  return bucket;
}

void bucket_display(queue<int> bucket){

  cout<<"\nBucket state: ";

  if(bucket.empty()){
    cout<<"\nBucket is empty!";
    return;
  }
  while(!bucket.empty()){
    cout<<bucket.front()<<" ";
    bucket.pop();
  }
  cout<<endl;
}

int main(){

  queue<int> bucket;
  int trans_rate,input_rate;
  cout<<"\nEnter size of bucket: ";
  cin>>bucket_size;
  cout<<"\nEnter transmission rate (constant): ";
  cin>>trans_rate;

  while(1){
    cout<<"\nEnter input_rate (packet burst size): ";
    cin>>input_rate;
    bucket = bucket_enter(bucket, input_rate);
    bucket_display(bucket);
    bucket = bucket_exit(bucket, trans_rate);
    cout<<"\nPacket transmitted.";
    bucket_display(bucket);
    cout<<"\n----------\n";

  }

  return 0;
}
