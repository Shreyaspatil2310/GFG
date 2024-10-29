//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<vector<int>>&adj, vector<int>&vis, int nd, int pr){
        vis[nd]=1;
        for(auto it:adj[nd]){
            if(vis[it]==0){
                if(dfs(adj,vis,it,nd)){
                    return 1;
                }
            }else if(it!=pr){
                return 1;
            }
        }
        return 0;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>vis(n,0);
        for(int i=0; i<n; ++i){
            if(vis[i]==0 && dfs(adj,vis,i,-1)){
                return 1;
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends