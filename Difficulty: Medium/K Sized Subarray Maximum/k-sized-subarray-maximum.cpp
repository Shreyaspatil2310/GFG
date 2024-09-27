//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        int first = 0;
        int second = 0;
        vector<int>ans;
        int smallmax = -1;
        int index = -1;
        int n = k;
        while(second<arr.size()){
           while(n){
               if(arr[second]>=smallmax){
                   smallmax = arr[second];
                   index = second;
               }
               second++;
               n--;
           }
           ans.push_back(smallmax);
           if(second == arr.size()){
               return ans;
           }
           if(index>first){
               first++;
               n = 1;
           }
           else{
               smallmax = -1;
               first++;
               second = first;
               n=k;
           }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends