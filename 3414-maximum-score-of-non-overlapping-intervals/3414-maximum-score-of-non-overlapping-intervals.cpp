class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& A) {
        int n = A.size();
        for (int i = 0; i < n; ++i)
            A[i].push_back(i); // A[i] = [l, r, w, origIdx]

        sort(A.begin(), A.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1]; // sort by end point
        });

        // dp[i][j] = best score using first i sorted intervals, picking up to j of them
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        // indices[i][j] = the actual chosen original indices (sorted ascending) achieving dp[i][j]
        vector<vector<vector<int>>> indices(n + 1, vector<vector<int>>(5));

        for (int i = 0; i < n; ++i) {
            int l = A[i][0];
            int w = A[i][2];
            int origIdx = A[i][3];

            // k = number of intervals (among first i, 0-indexed 0..i-1) whose end < l
            int k = lower_bound(A.begin(), A.begin() + i, l,
                        [](const vector<int>& t, int val){
                            return t[1] < val;
                        }) - A.begin();

            for (int j = 1; j < 5; ++j) {
                long long s1 = dp[i][j];               // skip current interval
                long long s2 = dp[k][j - 1] + w;        // take current interval

                if (s1 > s2) {
                    dp[i + 1][j] = s1;
                    indices[i + 1][j] = indices[i][j];
                    continue;
                }

                vector<int> newIndex = indices[k][j - 1];
                newIndex.push_back(origIdx);
                sort(newIndex.begin(), newIndex.end());

                if (s1 == s2 && indices[i][j] < newIndex) {
                    dp[i + 1][j] = s1;
                    indices[i + 1][j] = indices[i][j];
                } else {
                    dp[i + 1][j] = s2;
                    indices[i + 1][j] = newIndex;
                }
            }
            // carry forward j = 0 row unchanged (stays empty / 0)
        }

        return indices[n][4];
    }
};