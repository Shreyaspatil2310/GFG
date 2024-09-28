//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int solve(vector<int>& arr,vector<int>& dp,int idx, int& k){
        if(idx==0) return 0;
        
        if(dp[idx]!=-1) return dp[idx]; 
        int jmp2=INT_MAX;
        
        for(int i=1; i<=k; i++){
            if(idx-i>=0){
                
                int jmp=solve(arr,dp,idx-i,k)+abs(arr[idx]-arr[idx-i]);
                
                jmp2=min(jmp2,jmp);
                
            }
        }
        return dp[idx]=jmp2;
    }
    
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(arr,dp,n-1,k);
    }
};







//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends