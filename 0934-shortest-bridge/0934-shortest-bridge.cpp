class Solution {
    int dirs[5]= {1,0,-1,0,1};
    queue<pair<int, int>> q;
public:
    void dfs( vector<vector<int>> & grid, int i, int j){
        // ==2 means we have already visited this land cell
        // ==0 means its a water cell , just return otherwise u will convert land cell of the other island to 2 as well.. 
        
        if( !isvalid(i,j, grid.size()) || grid[i][j]==2 || !grid[i][j] )
            return;
        
        // change the land cell no.(1) to anything differnt
        grid[i][j]= 2;
        // and push it into the queue for bfs
        q.push( {i,j});
        // traverse to valid neigboring land cells and do the same....
        for( int k=0; k<4; k++){
            int x= i+ dirs[k] , y= j+ dirs[k+1];
            dfs( grid, x, y);
        }
    }
    
    int isvalid( int x, int y, int n){
        if( min(x,y)<0 || max(x,y)>=n )
            return 0;
        return 1;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n= grid.size();
        
        int flag=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if( grid[i][j] ){
                    flag=1;
                    dfs(grid,i,j);
                    break;
                }
            }
            if( flag)
                break;
        }
        
        // find the minimum dist using bfs
        
        int min_dist =INT_MAX, level = 0;
        
        // while queue is not empty
        while( !q.empty()){
            // current size of queue set
            int curr_size= q.size();
            
            // traverse through all the cells in the (level)th set of queue
            while( curr_size--){
                // get the row and column no. of the current cell
                // and pop it
                auto [row, col] = q.front();
                q.pop();
                
                // traverse through only the 4 neigboring cells ( if valid)
                for( int i =0; i<4; i++){
                    int x = row+ dirs[i], y= col + dirs[i+1];
                    
                    // we have found the cells of the other island , so just get the minimum distance..
                    if( isvalid(x,y, n) && grid[x][y] ==1){
                        min_dist = min( min_dist, level);
                    }
                    // if we get 0( water  cell), we will addd this to the queue for the next set of queue cells
                    if( isvalid(x, y, n) && grid[x][y] == 0){
                        q.push({x,y});
                        grid[x][y]=2;   // mark it as the land cell of the ist island...
                    }
                }
            }
            // increase level of the queue set
            ++level;
        }
        
        return min_dist;
    }
};