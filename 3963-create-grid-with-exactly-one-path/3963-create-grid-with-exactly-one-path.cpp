class Solution {
public:
    vector<string> createGrid(int m, int n) {       //T.C = O(m*n) S.C = O(m*n)
        
        vector<string> ans(m,string (n,'#'));

        for(int i = 0;i < m;i++){
            ans[i][0] = '.';
        }
        for(int j = 1;j < n;j++){
            ans[m-1][j] = '.';
        }
        return ans;
    }
};