//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int size) {
        sort(arr.begin() , arr.end());
        
        int miss = 1;
        int rep = -1;
        
        for(int i = 0; i < size ;i++){
            if( i > 0 && arr[i] == arr[i-1]){
                rep = arr[i]; 
            }
            if(arr[i] == miss){
                miss++;
            }
        }
        
        return {rep,miss};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends