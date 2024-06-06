//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long  sum=0;
       long long  sum1=0;
       long long N=n;
       for(long long i=0;i<N;i++){
          sum+=a[i]; 
          sum1+=i*a[i];
       }
       
       long long max=sum1;
       long long cur=sum1;
       for( long long i=1;i<N;i++){
           cur=cur-(sum-a[i-1])+(a[i-1]*(N-1));
           if(max<cur)
           max=cur;
       }
       
        return max;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends