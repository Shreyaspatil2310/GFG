//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        vector<vector<int>> ans;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,vector<int>> mp;
        
        int n = points.size();
        
        for(int i = 0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            
            int sq = ((x*x) + (y*y));
            
            mp[sq].push_back(i);
            
            pq.push(sq);
        }
        
        int i = 0;
        while(i<k){
            int d = pq.top();
            pq.pop();
            
            int s = mp[d].size();
            ans.push_back(points[mp[d][s-1]]);
            mp[d].pop_back();
            i++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends