//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    string printString(string s, char ch, int count) {
        int i =0;
        int cnt =0;
        for( i=0;i<s.size() ;i++){
            if(s[i] == ch) cnt++;
            if(cnt == count ) break;
        }
        i++;
        if(i>=s.size()) return "";
        return s.substr(i,s.size()-i);
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends