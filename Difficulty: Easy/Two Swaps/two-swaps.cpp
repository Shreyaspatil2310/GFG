//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool checkSorted(vector<int> &a) {
        int n = a.size();
        int m=3,j,temp;
        
        
        for(int i=0;i<n;i++)
        {
            while(a[i]!=i+1 && m)
            {
                j = a[i]-1;
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                if(m>1)
                    m-=1;
                else
                    return false;
            }
            
        }
        if(m==1 || m==3)
            return true;
        return false;
    }
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends