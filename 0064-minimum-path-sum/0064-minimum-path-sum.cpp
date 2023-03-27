class Solution {
    vector<vector<int>> dp;
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size(), n= grid[0].size();
        
        dp.resize(m, vector<int>(n, -1));
        
        return dfs(grid, 0,0);
    }
    int dfs(vector<vector<int>>& grid, int i, int j){
        int m= grid.size(), n= grid[0].size();
        
        if( i==m or j==n)
            return 20001;
        
        if( dp[i][j] != -1)
            return dp[i][j];
        
        if( i==m-1 and j==n-1)
            return grid[i][j];
        
        int sumfromright = dfs(grid, i, j+1);
        int sumfromdown = dfs(grid, i+1, j);
        
        return dp[i][j]= grid[i][j] + min( sumfromright, sumfromdown);
    }
};