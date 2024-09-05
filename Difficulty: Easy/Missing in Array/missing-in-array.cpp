//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:

int missingNumber(int n, vector<int>& arr) {
        int x = 0;
        sort(arr.begin(),arr.end());
        for(int i=1;i<=n;i++){
            if(arr[i-1]!=i){
                x=i;
                break;
            }
        }
        if(x == 0)return n;
        return x;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends