//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        unordered_map<int, int> prefixSumFreq;
    int count = 0;
    int prefix_sum = 0;

    // Initialize the hashmap with prefix sum 0 having a frequency of 1.
    prefixSumFreq[0] = 1;

    // Traverse the array.
    for (int i = 0; i < arr.size(); ++i) {
        // Update the prefix sum.
        prefix_sum += arr[i];

        // Check if (prefix_sum - tar) exists in the hashmap.
        if (prefixSumFreq.find(prefix_sum - tar) != prefixSumFreq.end()) {
            count += prefixSumFreq[prefix_sum - tar];
        }

        // Update the frequency of the current prefix sum in the hashmap.
        prefixSumFreq[prefix_sum]++;
    }

    return count;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends