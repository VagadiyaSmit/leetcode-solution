class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return 0;

        // dp[i][j]: number of ways to form t[0..j-1] from s[0..i-1]
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        // base case: empty t can be formed in exactly 1 way from any prefix of s
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j]; // always allowed: skip s[i-1]
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1]; // also allowed: use s[i-1]
                }
            }
        }

        return (int)dp[n][m];
    }
};