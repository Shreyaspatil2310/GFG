//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int computeGCD (int a, int b){
        while(b != 0){
            int temp = b;
            b  = a % b;
            a = temp;
        }
        return a;
    }
    vector<int> lcmAndGcd(int a, int b) {
       int gcd = computeGCD(a,b);
       int lcm = (a * b)/ gcd;
       return {lcm , gcd};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends