//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<vector<int>> dp;  // Memoization table

    int solve(vector<int>& arr, int sum, int index) {
        // Base cases
        if (sum == 0) return 1; // Found a subset that sums to the desired value
        if (index >= arr.size() || sum < 0) return 0; // No valid subset or out of bounds
        
        // Check if the subproblem is already solved
        if (dp[index][sum] != -1) return dp[index][sum];
        
        // Include the current element in the subset
        int incl = solve(arr, sum - arr[index], index + 1);
        // Exclude the current element from the subset
        int excl = solve(arr, sum, index + 1);
        
        // Store the result in the memoization table and return it
        return dp[index][sum] = incl || excl;
    }

    bool isSubsetSum(vector<int> arr, int sum) {
        int n = arr.size();
        dp.resize(n, vector<int>(sum + 1, -1)); // Initialize the memoization table with -1
        return solve(arr, sum, 0);
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends