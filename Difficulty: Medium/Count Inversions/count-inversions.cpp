//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], long long l, long long m, long long r)
    {
        long long int count=0;
        long long int left=l;
        long long int right=m+1;
        vector<long long int>v;
        while(left<=m && right<=r)
        {
            if(arr[left]<=arr[right])
            {
                v.push_back(arr[left]);
                left++;
            }
            
            else{
                v.push_back(arr[right]);
                count+=(m-left+1);
                right++;
            }
        }
        
        while(left<=m)
        {
            v.push_back(arr[left]);
            left++;
        }
        
        while(right<=r)
        {
            v.push_back(arr[right]);
            right++;
        }
        
        for(int i=l;i<=r;i++)
        {
            arr[i] = v[i-l];
        }
        
        return count;
    }
    // public:
    long long int mergeSort(long long arr[], long long l, long long r)
    {
        long long int count=0;
        if(l>=r)
        {
            return count;
        }
        
        long long int mid = (l+r)/2;
        count+=mergeSort(arr,l,mid);
        count+=mergeSort(arr,mid+1,r);
        count+=merge(arr,l,mid,r);
        return count;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        return mergeSort(arr,0,n-1);
    }
    

};




//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends