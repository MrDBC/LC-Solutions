class Solution {
    vector<int> dirs{0,1,0,-1,0};
public:
    int closedIsland(vector<vector<int>>& grid) {
       //intuition:  land cells at the edges will never be a part of any closed islands right
    // so what we can do is start from land cells( other than edge cells) and do dfs until u
        // reach some water cells(1), when u need to return.
        // if u can return back to the starting cell without traversing to any of the edge cells
        // ,u have got a closed island(+1), also once we encounter a land cell(change 0->#), to
        // avoid tle, continue doing until u have a (0) (ie., a land cell (not an edge cell))  
        
        int m= grid.size(), n= grid[0].size(), cnt=0;
        int count =0;
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                // we dont want to start at water cell(1)
                // or already used land cell (#)
                if( grid[i][j]==0)
                    count+= dfs(grid, i,j);
            }
        }
        
        return count;
    }
    int dfs( vector<vector<int>>& grid, int i, int j){
        int m= grid.size(), n= grid[0].size();
        
        // if u encounter water, return positive
        if( grid[i][j]==1)
                return 1;
        
        /// if u encounter an edge cell which is land, return negative
        if( !i or !j or i==m-1 or j==n-1){
            if( grid[i][j] != 1)
                return 0;
        }
        
        // land which is not an edge cell, return postive
        if( grid[i][j] == '#')
            return 1;
        
        int allok=1;
        // change the land cell(0) to any other symbol to avoid tle
        if( grid[i][j]==0){
            grid[i][j]= '#';
            
            // traverse the 4 directions and all of them should return
            // positive answers
            for(int d=0; d<4; d++){
                int x= i+ dirs[d], y= j+dirs[d+1];
                allok = min(allok, dfs(grid, x,y));
                
            }
        }
        
        
        return allok;
            
    }
};