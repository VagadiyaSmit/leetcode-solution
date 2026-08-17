class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n+1);
        for(int i = 0; i < n;++i){
            prefix[i + 1] = stoneValue[i] + prefix[i]; 
        }
        vector<vector<int>> memo(n,vector<int>(n,-1));

        function<int(int,int)> dfs = [&](int L,int R)-> int {
            if(L == R) return 0;
            if(memo[L][R] != -1) return memo[L][R];

            int best = 0;
            for(int split = L;split < R;++split){
                int left = prefix[split + 1] - prefix[L];
                int right = prefix[R + 1] - prefix[split + 1];

                if(2* min(left,right) <= best) break;

                if(left <= right) best = max(best,left + dfs(L,split));
                if(left >= right) best = max(best,right + dfs(split + 1,R));
            }
            return memo[L][R] = best;
        };
        return dfs(0,n - 1);
    }
};