//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector<pair<int,int> >adj[n+1];
        
        for(int i=0;i<m;i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<pair<int,int> >dist(n+1,{INT_MAX,-1});
        
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
        
        pq.push({0,1});
        
        dist[1] = {0,-1};
        
        while(!pq.empty()){
            
            auto p = pq.top();
            pq.pop();
            
            int d = p.first;
            int u = p.second;
            
            
            if(u==n){
                break;
            }
            
            for(int i=0;i<adj[u].size();i++){
                
                int v = adj[u][i].first;
                int wt = adj[u][i].second;
                
                if(dist[v].first == INT_MAX || dist[v].first > dist[u].first + wt ){
                    
                    dist[v].first = dist[u].first + wt;
                    dist[v].second = u;
                    
                    pq.push({dist[v].first,v});
                }
            }
        }
        
        vector<int>ans;
        
        if(dist[n].first==INT_MAX){
            
            ans.push_back(-1);
            return ans;
        }
        
        
        int i = n;
        
        while(i!=-1){
            
            ans.push_back(i);
            i = dist[i].second;
        }
        
        ans.push_back(dist[n].first);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends