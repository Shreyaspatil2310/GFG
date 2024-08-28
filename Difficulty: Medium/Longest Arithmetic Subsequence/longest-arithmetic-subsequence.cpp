//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return n;
        
        int ans = 0;
        unordered_map<int, int>dp[n+1];
        
        for(int i = 0; i< n ;i++){
            for(int j = 0 ; j < i ; j++){
                int diff = arr[i] - arr[j];
                int cnt = 1;
                
                if (dp[j].count(diff)){
                    cnt = dp[j][diff];
                }
                
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.lengthOfLongestAP(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends