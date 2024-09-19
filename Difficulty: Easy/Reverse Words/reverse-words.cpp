//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    string reverseWords(string s){ 
        string res = "";
        int len = s.length();

        for(int i = 0; i < len; i++){
            string word = "";
            while(i < len && s[i] != '.'){
                word += s[i++];
            }
            reverse(word.begin(), word.end());
            res += word + '.';
        }

        res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends