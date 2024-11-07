//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
   vector<int> findSplit(vector<int>& arr) {
        // code here
        vector<int> ans;

    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 3 != 0) {
        ans={-1,-1};
        return ans; 
    }

    int t = sum / 3;
    int pre = 0;

    for (int i = 0; i < arr.size(); i++) {
        pre += arr[i];
        
        
        if (pre == t) {
            pre = 0;
            ans.push_back(i);
            
            if(ans.size() == 2 && i < arr.size()-1){
                return ans;
            }
        }
    }
    
    ans={-1,-1};
    return ans;

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
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends