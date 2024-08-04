//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool PalinArray(vector<int> &arr) {
        
        int dup , temp,count, digit ;
        dup = digit = temp =count=0;
        for(int i=0;i<arr.size();i++){
             dup = arr[i];
             temp =0;
             
            while(arr[i]>0){
                digit = arr[i]%10;
             temp = ( temp *10 )+ digit ;
            arr[i]   = arr[i]/ 10;}
                
                if(temp != dup ){
                return false ;
            }
        }
            return true;
        
             
            
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << (ob.PalinArray(arr) ? "true" : "false") << endl;
    }

    return 0;
}

// } Driver Code Ends