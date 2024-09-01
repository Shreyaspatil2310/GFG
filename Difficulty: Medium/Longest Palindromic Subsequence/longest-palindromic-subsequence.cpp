//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solve(string a, string b) {
        int m = a.length();
        int n = b.length();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                
                if (a[i] == b[j]) {
                    curr[j] = 1 + next[j + 1]; 
                } else {
                    curr[j] = max(curr[j + 1], next[j]); 
                }
            }
            next = curr; 
        }
        return curr[0];
    }
    int longestPalinSubseq(string A) {
        string rev = A;
        reverse(rev.begin(), rev.end()); 
        return solve(A, rev); 
    }
};



//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends