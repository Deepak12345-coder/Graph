
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public: 
    void dfs(int node,vector<int>adj[],vector<int>&list,vector<int>&vis)
    {     vis[node]=1;
          list.push_back(node);
          for(auto it:adj[node])
          {
              if(vis[it]==0)
               {
                   dfs(it,adj,list,vis);
               }
          }
    }
   
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int>vis(V,0);
       vector<int>list;
       dfs(0,adj,list,vis);
       return list;
       
    }
    
};


int main() {
   
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    
    return 0;
}
