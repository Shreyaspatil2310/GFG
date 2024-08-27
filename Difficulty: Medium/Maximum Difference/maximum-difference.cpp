//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector<int> ls(n), rs(n);
        stack<int> st;

        // Finding nearest smaller to left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                ls[i] = 0;
            } else {
                ls[i] = st.top();
            }
            st.push(arr[i]);
        }
        while (!st.empty()) {
            st.pop();
        }
        // Finding nearest smaller to right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                rs[i] = 0;
            } else {
                rs[i] = st.top();
            }
            st.push(arr[i]);
        }
        // Calculate the maximum absolute difference
        int maxDiff = 0;
        for (int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, abs(ls[i] - rs[i]));
        }

        return maxDiff;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends