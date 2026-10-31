class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {            //T.C = O(m*n) S.C = O(n)
        const int MOD = 1e9 + 7;
        int  m = grid.size(),n = grid[0].size();
        
        vector<array<long long,2>> curr(n,{0,0}),next(n,{0,0});
        curr[0][0] = 1;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++)
                next[j] = {0,0};
            
            for(int j = 0;j < n;j++){
                long long right = curr[j][0];
                long long down = curr[j][1];

                if(grid[i][j] == 0){

                    long long t = (right + down) % MOD;
                    if(j+1 <n)
                        curr[j+1][0] = (curr[j+1][0] + t) % MOD;

                    if(i+1 < m)
                        next[j][1] = (next[j][1] + t) % MOD;
                    
                }
                else{
                    if(i+1 < m)
                        next[j][1] = (next[j][1] + right) % MOD;

                    if(j+1 <n)
                        curr[j+1][0] = (curr[j+1][0] + down) % MOD;

                }

            }
            if(i == m -1){
                return (curr[n-1][0] + curr[n-1][1]) % MOD;
            }
            swap(curr,next);
            
        }
        return 0;
    }
};