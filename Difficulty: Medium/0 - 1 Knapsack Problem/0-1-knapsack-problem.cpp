//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxCost(vector<int>& wt, vector<int>& val, vector<vector<int>>& dp, int i, int w) {
        if(i==wt.size() || w<0) return 0;
        if(dp[i][w]!=-1) return dp[i][w];
        if(w>=wt[i]) {
            return dp[i][w] = max(maxCost(wt, val, dp, i+1, w),
                                  maxCost(wt, val, dp, i+1, w-wt[i])+val[i]);
        }
        return dp[i][w] = maxCost(wt, val, dp, i+1, w);
    }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        vector<vector<int>> dp(wt.size(), vector<int>(W+1, -1));
        return maxCost(wt, val, dp, 0, W);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends