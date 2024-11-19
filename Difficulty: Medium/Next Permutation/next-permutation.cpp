//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int index1 = -1;
        stack<int> st;
        int index2 = -1;
        int len = arr.size();
        st.push(arr[len - 1]);
        int i = len - 2;
        while(i >= 0 && arr[i] >= st.top()){
            st.push(arr[i]);
            i--;
        }
        index1 = i;
        
        if(st.size() == len){
            sort(arr.begin(),arr.end());
            return;
        }
        i = len - 1;
        while(!st.empty()){
            
            if(arr[index1] < st.top()){
                index2 = i;
            }
            
            arr[i] = st.top();
            i--;
            st.pop();
        }
        swap(arr[index1],arr[index2]);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends