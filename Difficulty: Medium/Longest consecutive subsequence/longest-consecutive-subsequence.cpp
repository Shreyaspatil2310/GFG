//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
          map<int,int>mpp;
          for(int i=0;i<N;i++)
          {
              mpp[arr[i]]++;
          }
            int count=0;
          int maxSize=0;
          int num=0;
          for(auto it : mpp)
          {
              if(count==0)
              {
                num=it.first;
                count++;
              }
              else
              {
                  if(it.first==num+1)
                  {
                      count++;
                      num++;
                  }
                  else
                  {
                      count=1;
                      num=it.first;
                  }
                  
              }
              maxSize=max(count,maxSize);
          }
          return maxSize;
          
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends