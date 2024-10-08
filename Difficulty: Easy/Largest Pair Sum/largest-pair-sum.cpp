//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return -1;  // Handle cases where there are fewer than 2 elements.
        
        int max1 = INT_MIN, max2 = INT_MIN;
        
        // Find the two largest elements in one pass
        for (int i = 0; i < n; i++) {
            if (arr[i] > max1) {
                max2 = max1;  // Update second largest
                max1 = arr[i]; // Update largest
            } else if (arr[i] > max2) {
                max2 = arr[i]; // Update second largest
            }
        }
        
        return max1 + max2;
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
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends