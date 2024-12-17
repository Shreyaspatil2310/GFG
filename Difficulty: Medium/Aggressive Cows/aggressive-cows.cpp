//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPossible(vector<int>& stalls,int k,int currDist){
        int cowsCount = 1;
        int lastPlacedCow = stalls[0];
        
        for(int i=1;i<stalls.size();i++){
            int currCow = stalls[i];
            if(currCow-lastPlacedCow >= currDist){
                cowsCount++;
                if(cowsCount >= k) return true;
                lastPlacedCow = currCow;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        
        int minDist = 1;
        int maxDist = stalls[stalls.size()-1] - stalls[0];
        
        while(minDist <= maxDist){
            int currDist = minDist+(maxDist-minDist)/2;
            if(isPossible(stalls,k,currDist)){
                minDist = currDist+1;
            }
            else{
                maxDist = currDist-1;
            }
        }
        return maxDist;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends