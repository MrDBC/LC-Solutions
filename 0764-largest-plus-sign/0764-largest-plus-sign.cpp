class Solution {
    vector<int> dir{0,1,0,-1,0};
    // rowno , colno, direction
    int dp[501][501][4];
public:
    int dfs( int r, int c, int d, vector<vector<int>>& grid){
        int n= grid.size();
        
        
        if( dp[r][c][d] != -1)
            return dp[r][c][d];

        // new cell in the same direction
        int new_row = r+dir[d];
        int new_col = c+ dir[d+1];
        // basically if d=0 , our next cell is grid[r+dir[d]][c+dir[d+1]], that is grid[r][c+1] => RIGHT DIRECTION
        // we keep on moving in the same direction till we either hit the end of the grid
        // or we encounter a 0

        if( min(new_row,new_col)<0 or max(new_row,new_col)>=n or grid[new_row][new_col]==0)
            return 0;

        return dp[r][c][d]= 1+ dfs(new_row, new_col, d, grid);
    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for(auto p: mines)
            grid[p[0]][p[1]]=0;
        
        memset(dp, -1, sizeof(dp));
        int maxsize = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if( grid[i][j] ==0)
                    continue;
                
                maxsize = max( maxsize, 
                1+ min( dfs(i,j,0, grid), min(dfs(i,j,1,grid), min(dfs(i,j,2,grid), dfs(i,j,3,grid)))));
            }
        }

        return maxsize;
    }
};