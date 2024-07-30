//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  void solve(vector<string>&ans,string str,vector<vector<int>>&mat,int i,int j){
      
      if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]==0 || mat[i][j]==-1)
      return;
      if(i==mat.size()-1 && j==mat[0].size()-1){
          
          ans.push_back(str);
          return;
      }
      mat[i][j]=-1;
      solve(ans,str+"D",mat,i+1,j);
      solve(ans,str+"U",mat,i-1,j);
      solve(ans,str+"R",mat,i,j+1);
      solve(ans,str+"L",mat,i,j-1);
      
      mat[i][j]=1;
      return;
  }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
          vector<string>ans;
        solve(ans,"",mat,0,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends