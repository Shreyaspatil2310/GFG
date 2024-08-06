//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int isValid(string str) {
        // code here
        int n = str.size();
        for(int i = 0; i<n; i++){
            string temp = "";
            while(i<n && str[i]!='.'){
                temp += str[i];
                i++;
            }
            if(temp[0] == '0' && temp.size()!=1) return 0;
            int check = stoi(temp);
            if(check>255) return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends