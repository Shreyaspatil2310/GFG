//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        unordered_map<int,int> d;
        int comp;
        int count = 0;
        for(int i : arr)
        {
            comp = target - i;
            if(d.find(comp) != d.end())
            {
                count += d[comp];
            }
            if(d.find(i) != d.end())
                d[i]++;
            else
                d[i] = 1;
        }
        return count;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends