//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        int maxi = 0;
        int n = citations.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi,citations[i]);
        }
        vector<int> arr(maxi+2,0);
        
        for(int i=0;i<citations.size();i++){
            arr[0]++;
            arr[citations[i]+1]--;
        }
        
        for(int i=1;i<arr.size();i++){
            arr[i]+=arr[i-1];
        }
        
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]>=i) return i;
        }
        
        return 0;
        
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends