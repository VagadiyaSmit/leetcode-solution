class Solution {
public:
    int m,n;

    void dfs(vector<vector<int>> & G,int i,int j){   //keep eye on four side
        if (i < 0 || j < 0 || i >= n || j >= m || G[i][j] == 1) 
            return;
        G[i][j] = 1; 
        dfs(G, i + 1, j);     // down
        dfs(G, i - 1, j);     // up
        dfs(G, i, j + 1);     // right
        dfs(G, i, j - 1);     // left

    } 
    int closedIsland(vector<vector<int>>& grid) {               //T.C = S.C = O(RC) R = row C = column
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++) {           //for left/right border
            dfs(grid, i, 0);        // left column
            dfs(grid, i, m - 1);    // right column
        }
        
        for (int j = 0; j < m; j++) {          //for bottam/up border
            dfs(grid, 0, j);        // top row
            dfs(grid, n - 1, j);    // bottom row
        }
        
        int count = 0;              //count closed island
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    
    }
};