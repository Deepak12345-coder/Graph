#include <bits/stdc++.h>
using namespace std;
 void add_edge(vector<int>list[],int start,int end)
 {
   list[start].push_back(end);
   list[end].push_back(start);
 }  
 void print_list(vector<int>list[],int v)
 {
     for(int i=0;i<v;i++)
     {  
          cout<<i<<"->" ;
          for(int j=0;j<list[i].size();j++)
          {   
               cout<<list[i][j]<<" ";
            
          } 
          cout<<endl;
       
     }
 }
int main() 
{    
  int v;
  cin>>v;
  vector<int>list[v];
  
  add_edge(list,0,2);
  add_edge(list,1,2);
  add_edge(list,2,3);
  add_edge(list,3,4);

  print_list(list,v);
  return 0;
  
}
