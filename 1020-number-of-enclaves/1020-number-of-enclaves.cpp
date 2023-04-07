class Solution {
    vector<int> dirs{0,1,0,-1,0};
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m= grid.size(), n= grid[0].size();
        
        // intuition: we will start from a edge cell(which is a land)
        // and do a dfs, we return if we encounter a water cell,
        // but we keep on traversing while we encounter land cells, and
        // convert them into (water cells)
        // we then do a rescan of the matrix after all the dfs calls
        // and return the no of land cells
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if( !i or !j or i==m-1 or j==n-1 and grid[i][j]==1) 
                    dfs(grid, i,j);
            }
        
        int landcnt=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if( grid[i][j]==1)
                    landcnt++;
        
        return landcnt;
    }
    void dfs( vector<vector<int>>& grid, int i, int j){
        int m= grid.size(), n= grid[0].size();
        
        if(min(i,j)<0 or i==m or j==n or grid[i][j]==0)
            return ;
        
        grid[i][j]=0; // mark the land cell as water cell
        
        for(int d=0; d<4; d++){
            int x= i+dirs[d], y= j+dirs[d+1];
            
            dfs( grid, x,y);
        }
    }
};