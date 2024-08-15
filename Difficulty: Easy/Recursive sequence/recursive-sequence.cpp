//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    long long sequence(int n){
        long sum;
        long ans=0;
        long count = 1;
        for(int i= 1; i<=n;i++){
            sum=1;
            for(int j=1;j<=i;j++){
                sum = (sum*count)%1000000007;
                count++;
            }
            ans = (ans+sum)%1000000007;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends