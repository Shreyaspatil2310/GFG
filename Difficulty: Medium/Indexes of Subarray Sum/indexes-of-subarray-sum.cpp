//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        // Your code 
        int i = 0, j = 0;
        long long sum = 0;
        while(j<n and i<n)
        {
            if(s==0) {if(arr[j]==0) return {j+1,j+1}; }
            sum += 1LL*arr[j];
            if(sum == s) return {i+1,j+1};
            
            while(sum > s and i<n){
                sum -= arr[i];
                i++;
                if(sum == s and s != 0) return {i+1,j+1};
                
            }
            j++;
        }
        return {-1};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends