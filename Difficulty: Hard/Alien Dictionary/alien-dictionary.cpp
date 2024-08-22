//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int n, int k)
    {
        vector<int> adj[k];
    
        for (int i = 0; i < n - 1; i++)
        {
            string a = dict[i], b = dict[i + 1];
            for (int i = 0; i < min(a.size(), b.size()); i++)
            {
                if (a[i] != b[i])
                {
                    adj[a[i] - 'a'].push_back(b[i] - 'a');
                    break; 
                }
            }
        }
    
        // find the indegree for topo-sort.
        vector<int> indegree(k, 0);
        for (auto el : adj)
        {
            for (auto ch : el)
            {
                indegree[ch]++;
            }
        }
        
        // cout<<"indegree content"<<endl;
        // for(auto it:indegree){
        //     cout<<it<<" ";
        // }cout<<endl;
    
        queue<int> q;
        // find the one havg indegree 0, and push into the queue.
        for (int i = 0; i < k; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    
        string ans = "";
    // element can only be in the queue if its indegree will be 0. // a/c kahn's algo
        while (!q.empty())
        {
            int num = q.front();
            q.pop();
    
            ans += (num + 'a');
    
            for (auto adjNode : adj[num])
            {
                if(--indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
    
        // for ( auto el:ans) {
        //     cout<<el<<" ";
        // }cout<<endl;
        
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends