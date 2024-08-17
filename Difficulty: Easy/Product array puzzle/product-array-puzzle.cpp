//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        vector<long long int>ans;
        long long int n=nums.size();
        long long int pro=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                pro*=nums[j];
            }
            ans.push_back(pro);
            pro=1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends