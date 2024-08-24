//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int knapSack(int w, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<int> nxt(w+1), cur(w+1);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=w;j++){
                int notTake = nxt[j], take = 0;
                if(wt[i]<=j) take = val[i]+nxt[j-wt[i]];
                cur[j] = max(take,notTake);
            }
            nxt=cur;
        }
        return cur[w];
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends