//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for
class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        int count = 0,i,j; 
        for(i=1;i<=r*2;i++){
            for(j=1;j<=r*2;j++){
                if(((i*i)+(j*j))<=(r*r*4))
                    count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends