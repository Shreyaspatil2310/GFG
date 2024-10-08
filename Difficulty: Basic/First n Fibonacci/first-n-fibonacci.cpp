//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    vector<long long> printFibb(int n) 
    {
        vector<long long>ans;
        long long first=1;
        long long second=1;
        ans.push_back(first);
        if(n>1){
        ans.push_back(second);
        }
        for(int i=2;i<n;i++){
            long long next=first+second;
            ans.push_back(next);
            first=second;
            second=next;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends