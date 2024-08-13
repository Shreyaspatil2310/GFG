//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  long long reverseNumber(long long num) {
    long long reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

    long long isSumPalindrome(long long n) {
         long long rev, sum, temp;

    for (int i = 0; i < 5; ++i) {
        sum = n;
        rev = 0;

        while (sum > 0) {
            temp = sum % 10;
            rev = rev * 10 + temp;
            sum /= 10;
        }

        if (n == rev) {
            return n;
        }

        n += rev;

        if (n == reverseNumber(n)) {
            return n;
        }
    }

    return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution ob;
        cout << ob.isSumPalindrome(n) << endl;
    }
    return 0;
}

// } Driver Code Ends