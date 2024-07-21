//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        int n=arr.size();
        long long int ans=1;
        int mn=INT_MIN;
        int mod =1e9+7; 
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                continue;
            }
            if(arr[i]<0)
            {
                mn=max(mn,arr[i]);
            }
            ans=(ans*arr[i])%mod;
        }
        if(ans<0)
        {
           return  ans/mn;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends