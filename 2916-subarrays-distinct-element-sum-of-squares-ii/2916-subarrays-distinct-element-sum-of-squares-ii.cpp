class Solution {
public:
    const long long MOD = 1e9 + 7;
    int n;
    vector<long long> st, st1, lazy;   // st = sum of d^2, st1 = sum of d

    void apply(int i, int l, int r, long long val) {
        long long len = r - l + 1;
        st[i]  += 2 * val * st1[i] + len * val * val;  // uses OLD st1
        st1[i] += len * val;
        if (l != r) {
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
    }

    void update(int s, int e, int i, int l, int r, long long val) {
        // push pending lazy of this node
        if (lazy[i] != 0) {
            long long lz = lazy[i];
            lazy[i] = 0;
            apply(i, l, r, lz);
        }

        if (l > e || r < s) return;          // no overlap

        if (l >= s && r <= e) {              // full overlap
            apply(i, l, r, val);
            return;
        }

        int mid = l + (r - l) / 2;           // partial overlap
        update(s, e, 2*i+1, l, mid, val);
        update(s, e, 2*i+2, mid+1, r, val);

        st1[i] = st1[2*i+1] + st1[2*i+2];
        st[i]  = st[2*i+1]  + st[2*i+2];
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        st.assign(4*n, 0);
        st1.assign(4*n, 0);
        lazy.assign(4*n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int s = last[nums[i]] + 1;
            update(s, i, 0, 0, n - 1, 1);
            ans = (ans + st[0]) % MOD;
            last[nums[i]] = i;
        }
        return (int)ans;
    }
};