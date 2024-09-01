//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
  
    int solve(string &a, string &b, int i, int j,vector<vector<int>>&dp){
        
        if (i == a.length()) return 0;
        if (j == b.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solve(a, b, i+1, j+1, dp);
        }
        else{
            ans= max(solve(a, b, i, j+1, dp), solve(a, b, i+1, j, dp));
        }
        
        return dp[i][j] = ans;
    }
    int lcs(int n, int m, string str1, string str2) {
        vector<vector<int>>dp(n, vector<int>(m , -1));
        return solve(str1,str2,0,0,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    }
    return 0;
}

// } Driver Code Ends