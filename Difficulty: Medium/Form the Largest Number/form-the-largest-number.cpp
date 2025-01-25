//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findLargest(vector<int>& arr) {
        // Convert integers to strings for easy concatenation and comparison
        vector<string> nums;
        for (int num : arr) {
            nums.push_back(to_string(num));
        }
        
        // Custom comparator to sort the strings in such a way that maximizes the concatenated number
        sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
            return a + b > b + a; // If a+b is greater than b+a, a should come before b
        });
        
        // If the largest number is '0', return "0" (handle the case where all numbers are 0)
        if (nums[0] == "0") {
            return "0";
        }
        
        // Concatenate all the strings together to form the largest number
        string result = "";
        for (const string& num : nums) {
            result += num;
        }
        
        return result;
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
        string ans = ob.findLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends