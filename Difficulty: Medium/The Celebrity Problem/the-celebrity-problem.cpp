//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

#include <vector>
#include <stack>

class Solution 
{
    private:
    bool knows(std::vector<std::vector<int>>& M, int a, int b) {
        return M[a][b] == 1;
    }
    
    public:
    int celebrity(std::vector<std::vector<int>>& M, int n) 
    {
        std::stack<int> s;
        for (int i = 0; i < n; i++) {
            s.push(i);
        }
        
        // Find the potential celebrity
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if (knows(M, a, b)) {
                s.push(b);
            } else {
                s.push(a);
            }
        }
        
        int ans = s.top();
        
        // Check if the potential celebrity is a real celebrity
        int zeroCount = 0;
        for (int i = 0; i < n; i++) {
            if (M[ans][i] == 0) {
                zeroCount++;
            }
        }
        if (zeroCount != n) return -1;
        
        int oneCount = 0;
        for (int i = 0; i < n; i++) {
            if (M[i][ans] == 1) {
                oneCount++;
            }
        }
        if (oneCount != n - 1) return -1;
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends