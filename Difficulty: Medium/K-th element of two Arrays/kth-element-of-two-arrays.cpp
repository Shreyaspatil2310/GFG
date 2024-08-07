//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int m=0,n=0,n1=arr1.size(),n2=arr2.size(),ans=-1;
        while(k>0){
            if(m<n1 && n<n2){
                if(arr1[m]<arr2[n]) ans=arr1[m++];
                else ans=arr2[n++];
            }
            else if(m<n1) ans=arr1[m++];
            else ans=arr2[n++];
            k--;
        }
        return ans;// code here
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends