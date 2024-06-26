//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    int num=n;
        int rev=0;
        
        while(n){
            int ld=n%10;
            n=n/10;
            rev=ld+rev*10;

        }
        if(rev==num)return "Yes";
        else return "No";
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends