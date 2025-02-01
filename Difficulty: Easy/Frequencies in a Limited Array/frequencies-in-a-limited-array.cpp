//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> frequencyCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, 0);  

        for(int i = 0; i < n; i++) {
            if (arr[i] > 0 && arr[i] <= n) {  
                result[arr[i] - 1]++;  
            }
        }
        
        return result;  
    }
};



//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.frequencyCount(a);

        // Print the result in the required format
        if (result.empty()) {
            cout << "[]"; // Print empty brackets if no duplicates are found
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends