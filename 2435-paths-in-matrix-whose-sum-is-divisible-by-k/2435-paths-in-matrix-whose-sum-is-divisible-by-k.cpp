class Solution {
    // int dp[50001][50001][50];
    vector<vector<vector<int>>> dp;
    int mod= 1e9+7;
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m= grid.size(), n= grid[0].size();
        dp.resize(m + 1, vector<vector<int>>(n + 1, vector<int>(k , -1)));
        
        return dfs(grid,k,0,0, 0);
    }
    int dfs(vector<vector<int>>& grid, int k, int i, int j, int sum ){
        
        int m= grid.size(), n= grid[0].size();
        
        if(i>=m or j>=n)
            return 0;
        
        if( dp[i][j][sum%k] != -1)
            return dp[i][j][sum%k];
        
        if( i==m-1 and j==n-1){
            return ((sum+grid[i][j])%k == 0);
        }
        
        int right = dfs(grid, k, i, j+1, (sum+grid[i][j])%k) %mod;
        int down  = dfs(grid, k, i+1, j, (sum+grid[i][j])%k) %mod;
        
        return dp[i][j][sum%k]= (right+down)%mod;
        
    }
};