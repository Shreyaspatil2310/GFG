//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string solve(string& str,int left,int right){
        while((left>=0 && right<str.size())&& (str[left]==str[right])){
            left--;
            right++;
        }
        return str.substr(left+1, right - left - 1);
    }
    string longestPalin (string S) {
        string ans="";
        for(int i=0;i<S.size();i++){
            string s1 = solve(S, i, i + 1); // even length palindrome
            string s2 = solve(S, i, i); // odd length palindrome
            
            
            if (s1.size() > ans.size()) ans = s1;
            if (s2.size() > ans.size()) ans = s2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends