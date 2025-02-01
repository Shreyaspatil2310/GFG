//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#include <cmath>

class Solution {
  public:
    bool armstrongNumber(int n) {
        int original = n;
        int z = to_string(n).size();  
        int sum = 0;
        
        while (n != 0) {
            int d = n % 10;
            sum += pow(d, z);  
            n /= 10;
        }
        
        return sum == original;
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
        bool flag = ob.armstrongNumber(n);
        if (flag) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends