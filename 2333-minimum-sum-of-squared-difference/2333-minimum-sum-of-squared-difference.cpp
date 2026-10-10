class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {    
        //T.C = O(n + M) S.C = O(M)   
        //M = max |diff| ≤ 10⁵
        
        //work simply to return the diff of squere of array but one conditon for all k use as a decrement(as soon as minimum)of output or budget

        int n = nums1.size();

        const int MAXD = 100000;
        vector<long long> cnt(MAXD + 1, 0);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            cnt[d]++;
            mx = max(mx, d);
        }

        long long k = (long long)k1 + k2;

        for (int d = mx; d >= 1 && k > 0; d--) {
            if (cnt[d] == 0) continue;

            if (k >= cnt[d]) {
            
                k -= cnt[d];
                cnt[d - 1] += cnt[d];
                cnt[d] = 0;
            } else {
                
                cnt[d] -= k;
                cnt[d - 1] += k;
                k = 0;
            }
        }

        
        long long ans = 0;
        for (long long d = 1; d <= mx; d++)
            ans += cnt[d] * d * d;

        return ans;
    }
};