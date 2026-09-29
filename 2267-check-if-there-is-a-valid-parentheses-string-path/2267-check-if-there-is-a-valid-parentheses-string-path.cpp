class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) & 1) 
            return false;       // if Path length is m+n-1; an odd length can never be balanced.

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') 
            return false;      // start with '(' and end with ')'.
        
        vector<bitset<101>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<101> prev;

                if (i == 0 && j == 0) {
                    prev[0] = 1;            // start with balance 0 before the first char
                } else {
                    if (i > 0) prev |= dp[j];      // from above (dp[j] still holds row i-1)
                    if (j > 0) prev |= dp[j - 1];  // from left (dp[j-1] already updated for row i)
                }

                // '(' raises every balance by 1, ')' lowers by 1.
                // ')' on balance 0 is shifted out, which discards invalid states.
                dp[j] = (grid[i][j] == '(') ? (prev << 1) : (prev >> 1);
            }
        }

        // Valid iff balance 0 is reachable at the bottom-right cell.
        return dp[n - 1][0];
    }
};