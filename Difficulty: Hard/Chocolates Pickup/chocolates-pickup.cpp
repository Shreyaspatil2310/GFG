//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // DP table with dimensions [n][m][m], initialized to -1
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        // Helper function to calculate the maximum chocolates collected
        // by two robots starting from row i with columns j1 and j2.
        function<int(int, int, int)> choco = [&](int i, int j1, int j2) -> int {
            // If out of bounds
            if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return 0;
            
            // If we have reached the last row
            if (i == n - 1) {
                // If both robots are on the same cell, collect chocolates once
                if (j1 == j2) return grid[i][j1];
                // Otherwise, collect chocolates from both cells
                return grid[i][j1] + grid[i][j2];
            }
            
            // If already computed, return the stored value
            if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
            
            // Explore all 9 possible moves (for each robot: left, down, right)
            int maxChocolates = 0;
            for (int move1 = -1; move1 <= 1; ++move1) {
                for (int move2 = -1; move2 <= 1; ++move2) {
                    int next_j1 = j1 + move1;
                    int next_j2 = j2 + move2;
                    maxChocolates = max(maxChocolates, choco(i + 1, next_j1, next_j2));
                }
            }
            
            // Add chocolates from the current cells
            if (j1 == j2) {
                dp[i][j1][j2] = grid[i][j1] + maxChocolates;
            } else {
                dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + maxChocolates;
            }
            return dp[i][j1][j2];
        };
        
        // Start from the top row with Robot1 at (0, 0) and Robot2 at (0, m-1)
        return choco(0, 0, m - 1);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends