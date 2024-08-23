//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const long long int mod = 1e9+7;
    long long int f(int n, vector<long long int> &dp) {
        if(n<=1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (f(n-1, dp)+f(n-2, dp))%mod;
    }
    long long int topDown(int n) {
        vector<long long int> dp(n+1, -1);
        return f(n, dp);
    }
    long long int bottomUp(int n) {
        if(n<=1) return n;
        long long int prev=1;
        long long int prev2=0;
        for(int i=2; i<=n; i++) {
            long long int fibo = (prev+prev2)%mod;
            prev2 = prev;
            prev = fibo;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends