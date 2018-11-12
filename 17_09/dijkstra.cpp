#include<iostream>
using namespace std;

class Dijkstra
{
  private:
   int cost_matrix[20][20],distance[20],marked[20],previous_node[20];

  public:
    int N,M,S,flag;
    void read_graph();
    void display_costmatrix();
    Dijkstra();
    void Dijkstras_algorithm();
    void path(int p);
};

Dijkstra::Dijkstra()
{
 for(int i=1;i<=20;i++)
 for(int j=1;j<=20;j++)
   cost_matrix[i][j]=5000;
 for(int i=1;i<=N;i++)
  previous_node[i]=0;
 flag=0;
}

void Dijkstra::read_graph()
{
 int i,j,k,w;
 cout<<"Enter no of vertices\n";
 cin>>N;
 cout<<"Enter no of edges\n";
 cin>>M;
 cout<<"Enter vertices and weights respectively [ u v w ]\n";
 for(k=1;k<=M;k++)
 {
  cin>>i>>j>>w;
  cost_matrix[i][j]=w;
 }

  cout<<"Enter source vertex\n";
  cin>>S;
}




void Dijkstra::display_costmatrix()
{
 for(int i=1;i<=N;i++)
 {
 for(int j=1;j<=N;j++)
 {
  cout<<cost_matrix[i][j]<<"\t";
 }
 cout<<endl;
 }
}


void Dijkstra::Dijkstras_algorithm()
{
  int min_cost,u;
  for(int i=1;i<=N;i++)
  {
   distance[i]=cost_matrix[S][i];
   marked[i]=0;
  }

 marked[S]=1;
 distance[S]=0;

 cout<<"\n----------------\n";
 cout<<"\nDistance array after iteration "<<"1"<<" : ";
 for(int i=1;i<=N;i++){
   cout<<distance[i]<<" ";
 }
 cout<<"\nMarked array after iteration "<<"1"<<" : ";
 for(int i=1;i<=N;i++){
   cout<<marked[i]<<" ";
 }
 for(int i=1;i<=N;i++)
 {
   cout<<"\n";
   cout<<S<<"-->"<<i<<":"<<distance[i]<<"\t";
   cout<<"Path:";

    path(i);
    if(flag==0)
     cout<<i;

 }

 for(int it_num=2;it_num<=N-1;it_num++)
 {
  min_cost=10000;

  for(int i=1;i<=N;i++)
  {
   if(distance[i]<=min_cost && marked[i]==0)
   {
      min_cost=distance[i];
      u=i;

   }
  }

 marked[u]=1;

   for(int i=1;i<=N;i++)
   {
    if(marked[i]==0 && cost_matrix[u][i]!=5000)
    {
       if(distance[i]>distance[u]+cost_matrix[u][i])
       {
         distance[i]=distance[u]+cost_matrix[u][i];
         previous_node[i]=u;
       }

     }


   }
   cout<<"\n----------------\n";
   cout<<"\nDistance array after iteration "<<it_num<<" : ";
   for(int i=1;i<=N;i++){
     cout<<distance[i]<<" ";
   }
   cout<<"\nMarked array after iteration "<<it_num<<" : ";
   for(int i=1;i<=N;i++){
     cout<<marked[i]<<" ";
   }
   for(int i=1;i<=N;i++)
   {
     cout<<"\n";
     cout<<S<<"-->"<<i<<":"<<distance[i]<<"\t";
     cout<<"Path:";

      path(i);
      if(flag==0)
       cout<<i;

   }

 }





}


void Dijkstra::path(int p)
{


 if (previous_node[p]==0)
 {
      if(distance[p]!=5000)
      {
       flag=0;
       cout<<S;
       return;
      }
      else
      {
       cout<<"No path possible.\n";
       flag=1;
       return;

      }
 }

    path( previous_node[p]);
    cout<<previous_node[p];


}


int main()
{

 Dijkstra obj;
 obj.read_graph();
 obj.display_costmatrix();
 obj.Dijkstras_algorithm();
 return(0);

}
