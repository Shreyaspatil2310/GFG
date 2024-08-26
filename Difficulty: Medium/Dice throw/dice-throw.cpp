//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    long long solve(int dice, int faces, int target, vector<vector< long long >>& dp){
        
        if(target < 0) return 0;
        if(dice == 0 && target != 0) return 0;
        if(target == 0 && dice != 0) return 0;
        if(target == 0 && dice == 0) return 1; 
        
        if(dp[dice][target] != -1) return dp[dice][target];
        long long ans  = 0;
        
        for(int i = 1 ; i <= faces ; i++){
            ans = ans + solve(dice -1 , faces , target -i , dp);
        }
        return dp[dice][target] = ans;
     }
    
     long long noOfWays(int m, int n, int x) {
        vector<vector< long long >>dp( n +1 , vector<long long >( x +1 , -1));
        return solve(n , m , x ,dp);
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ts;
        getline(cin, ts);
        stringstream ss(ts);
        int number;
        int f = 0;
        int m, n, x;
        while (ss >> number) {
            if (f == 0)
                m = number;
            else if (f == 1)
                n = number;
            else
                x = number;
            f++;
        }

        // cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(m, n, x) << endl;
    }
    return 0;
}
// } Driver Code Ends