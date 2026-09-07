class Solution {
public:
    int distinctSubseqII(string s) {  // T.C = O(n) S.C = O(1)
        const int MOD = 1e9 + 7;
        int n = s.size();
        
        // dp = number of distinct subsequences (including empty) so far
        long long dp = 1; // dp[0] = 1 (empty subsequence)
        
        // last[c] = dp value just BEFORE the previous occurrence of c was processed
        vector<long long> last(26, 0);
        
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            long long prevDp = dp; // this becomes dp[i-1] relative to next char
            dp = (2 * dp - last[c] + MOD) % MOD; // +MOD guards against negative
            last[c] = prevDp;
        }
        
        // subtract 1 for the empty subsequence, add MOD in case dp was 0 mod-wise
        return (int)((dp - 1 + MOD) % MOD);
    }
};