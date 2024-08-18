//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        
        if (arr.size()==1){
            return false;
        }
        
        int i=0;
        int j=arr.size()-1;
        
        int n1=0;
        vector<int>num1;
        vector<int>num2;
        int n2=0;

        while(i<=j){
            if (n1<=n2){
            	n1+=arr[i];
            	
            	i++;
            }
            else {
            	n2+=arr[j];
            	j--;
            }
        }
        if (n1==n2){
            return true;
        } 
        else {
        	return false;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends