class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {  // T.C = O(n) S.C = O(1)
        int n = stoneValue.size();
        int dp[4] = {0,0,0,0};
        string ans[] = {"Bob","Tie","Alice"};
        for(int i = n-1;i>= 0;i--){
            dp[i & 3] = stoneValue[i]-dp[(i+1) & 3];
            if(i+1 <n){
                dp[ i & 3] = max(dp[ i & 3],stoneValue[i] + stoneValue[ i + 1]- dp[(i +2 )& 3]);
            }
            if( i+2 < n){
                dp[i & 3] = max(dp[i & 3],stoneValue[i]+stoneValue[i + 1]+stoneValue[i + 2]- dp[(i + 3) & 3]);

            }
        
        }
        return ans[(dp[0] > 0) - (dp[0] < 0) + 1];
    }
};