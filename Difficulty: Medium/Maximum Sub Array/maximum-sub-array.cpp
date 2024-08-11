//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    vector<int> findSubarray(int n, int a[]) {
        vector<int> result;
        int maxSum = 0, currentSum = 0;
        int start = 0, end = 0, tempStart = 0;
        
        for (int i = 0; i < n; i++) {
            // If the current element is non-negative, add it to the current sum
            if (a[i] >= 0) {
                currentSum += a[i];
            } else {
                // If it's negative, reset the current sum and move the tempStart to the next position
                currentSum = 0;
                tempStart = i + 1;
            }
            
            // Update maxSum if the current sum is greater, or if it's equal and the subarray is longer
            if (currentSum > maxSum || (currentSum == maxSum && i - tempStart > end - start)) {
                maxSum = currentSum;
                start = tempStart;
                end = i;
            }
        }
        
        // If no positive sum was found, return -1
        if (maxSum == 0) {
            result.push_back(-1);
        } else {
            // Build the result vector with the elements from the subarray
            for (int i = start; i <= end; i++) {
                result.push_back(a[i]);
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(n, a);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends