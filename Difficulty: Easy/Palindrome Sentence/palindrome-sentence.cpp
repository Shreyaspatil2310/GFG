//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function template for C++
//User function template for C++
class Solution{
public:	
	bool sentencePalindrome(string s) 
	{
	    string str;
	    for(int i=0; i<s.length(); i++){
	        if(islower(s[i])){
	            str+=s[i];
	        }
	    }
	    int n=str.length();
	    int i=0, j=(n-1);
	    while(i<=j){
	        if(str[i]!=str[j]){
	            return false;
	        }
	        i++;
	        j--;
	    }
	    return true;
	}
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        Solution ob;
        cout<<ob.sentencePalindrome(str)<<endl;
    }
    return 0;
}  


// } Driver Code Ends