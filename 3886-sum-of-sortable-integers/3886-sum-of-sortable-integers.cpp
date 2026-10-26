class Solution {
public:
    bool check(const vector<int>& a, int k) {
        int n = a.size();
        int prevMax = 0; 

        for (int l = 0; l < n; l += k) {       
            int r = l + k - 1;
            int drops = 0;
            int mn = a[l], mx = a[l];          

            for (int i = l; i <= r; i++) {
                int nxt = (i == r) ? l : i + 1;    
                if (a[i] > a[nxt]) {
                    if (++drops > 1) return false;
                    mx = a[i];                     
                    mn = a[nxt];                  
                }
            }

            if (mn < prevMax) return false;   
            prevMax = mx;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {       //T.C: O(n · d(n))   , d(n) = constant  S.C = O(1)
        int n = nums.size();
        int ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k == 0 && check(nums, k)) ans += k;
        }
        return ans;
    }
};
