//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(vector<int>& height,int i,int n,vector<int>& dp){
        if(i==n-1){
            return 0;
        }
        if(i>=n){
            return 1e5;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int a =abs(height[i+1]-height[i]) + helper(height,i+1,n,dp);
        int b =abs(height[i+2]-height[i]) + helper(height,i+2,n,dp);
        return dp[i]=min(a,b);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        return helper(height,0,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends