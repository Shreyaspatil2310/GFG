//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    int get_index(vector<int> &arr){
        
        int st = 0 ;
        int ed = arr.size()-1;
        while(st < ed){
            int mid = (st+ed)/2;
            
            if(arr[0] <= arr[mid]){
                st = mid+1;
            }
            else ed = mid;
        }
        return st;
    }
    int binary_search(vector<int>&arr,int s,int e,int &k){
        int st = s;
        int end =e;
        while(st <= end){
            int mid = (st+end)/2;
            if(arr[mid]==k) return mid;
            else if(arr[mid] > k) end = mid -1;
            else st = mid+1;
        }
        return -1;
    }
  public:
    int search(vector<int>& arr, int key) {
        int pivot  = get_index(arr);
        int n = arr.size();
        if(arr[pivot] <= key && key <= arr[n-1]) {
            return binary_search(arr,pivot,n-1,key);
        }
        else return binary_search(arr,0,pivot-1,key);
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends