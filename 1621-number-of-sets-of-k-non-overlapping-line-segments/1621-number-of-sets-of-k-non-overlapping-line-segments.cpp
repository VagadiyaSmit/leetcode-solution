

class Solution {
public:
    int numberOfSets(int n, int k) {        //T.C = O(n*k)  = S.C

        // We must return answer modulo 1,000,000,007
        const int MOD = 1e9 + 7;

        // dp[i][j] =
        // number of ways to create exactly j segments
        // using points 0 through i.
        vector<vector<long long>> dp(
            n, vector<long long>(k + 1, 0)
        );

        // BASE CASE:
        // 0 segments can always be made in exactly 1 way:
        // choose nothing.
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        // Try every possible number of segments
        for (int j = 1; j <= k; j++) {

            // Stores:
            // dp[0][j-1] + dp[1][j-1] + ... + dp[i-1][j-1]
            long long prefix = 0;

            // Process points from left to right
            for (int i = 0; i < n; i++) {

                // With only point 0, we can't make
                // any positive number of segments.
                if (i > 0) {

                    // TWO CASES:
                    //
                    // 1. j segments were already completed
                    //    before point i:
                    //       dp[i-1][j]
                    //
                    // 2. A new segment ends at i:
                    //       prefix
                    //
                    dp[i][j] =
                        (dp[i - 1][j] + prefix) % MOD;
                }

                // Add current previous-layer value
                // so it can participate in future calculations.
                prefix =
                    (prefix + dp[i][j - 1]) % MOD;
            }
        }

        // Last point = n-1
        // Number of segments = k
        return (int)dp[n - 1][k];
    }
};