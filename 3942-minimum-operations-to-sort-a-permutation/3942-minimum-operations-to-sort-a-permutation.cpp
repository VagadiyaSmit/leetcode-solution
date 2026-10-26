class Solution {
public:
    int minOperations(vector<int>& a) {         //T.C = O(n) S.C = O(1)
        int n = a.size();
        if (n == 1) return 0;

        int ans = 1e9;

        
        {
            int cnt = 0, pos = -1;
            for (int i = 0; i < n; i++) {
                int next = (i + 1) % n;
                if (a[next] < a[i]) {      
                    cnt++;
                    pos = i;               
                }
            }
            if (cnt == 1) {
                
                ans = min(ans, (pos + 1) % n);
                ans = min(ans, 2 + (n - pos - 1));
            }
        }

        
        {
            int cnt = 0, pos = -1;
            for (int i = 0; i < n; i++) {
                int next = (i + 1) % n;
                if (a[next] > a[i]) {      
                    cnt++;
                    pos = i;               
                }
            }
            if (cnt == 1) {
                
                ans = min(ans, 1 + (pos + 1) % n);
                ans = min(ans, 1 + (n - pos - 1));
            }
        }

        return ans < 1e9 ? ans : -1;
    }
};