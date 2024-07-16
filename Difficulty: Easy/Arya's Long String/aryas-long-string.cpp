//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int fun(string s, int k, int n, char c) {
        int ans=0;
        int N=s.size();
        for(int i=0;i<N;i++){
            if(s[i]==c) ans++;
        }
        ans=ans*(n/N);
        for(int i=0;i<(n%N);i++) if(s[i]==c) ans++;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t, i, n, k;
    char c;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cin >> k >> n >> c;
        Solution ob;
        cout << ob.fun(s, k, n, c) << endl;
    }
    return 0;
}

// } Driver Code Ends