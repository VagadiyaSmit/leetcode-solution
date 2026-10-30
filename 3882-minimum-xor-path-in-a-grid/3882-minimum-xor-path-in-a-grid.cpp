class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<bool>>>dp(n,vector <vector<bool>>(m,vector<bool>(1<<10,false)));

        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int x = 0; x < (1 << 10); x++) {
                    if (!dp[i][j][x]) continue;

                    // move down
                    if (i + 1 < n)
                        dp[i + 1][j][x ^ grid[i + 1][j]] = true;

                    // move right
                    if (j + 1 < m)
                        dp[i][j + 1][x ^ grid[i][j + 1]] = true;
                }
            }
        }

        int ans = 1e9;
        for (int x = 0; x < (1 << 10); x++) {
            if (dp[n - 1][m - 1][x]) {
                ans = min(ans, x);
            }
        }

        return ans;
    }
};