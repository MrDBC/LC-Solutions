class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // u can either start from top-right or bottom left
        // why? becoz lets say , u start at either:
        // top-left: then moving down ur vals decrease. also moving right ur vals decrease
        // so u cant decide where to move
        // similar problem if we start at bottom-right
        // but if we start at top-right, moving down vals decrease & moving left vals increase
        // now we have a choice to either move left or down
        int m= grid.size(), n= grid[0].size();
        
        int r=m-1, c=0, cnt=0;
        
        while( r>=0 and c<n){
            
            // if so, we can say that all vals to grid[r][c] are also negative
            // so count them
            if( grid[r][c] < 0){
                cnt+= (n-c);
                --r; // move up , since u counted this row
            }
            else
                ++c; // if grid[r][c] is positive, we need to move right in search of negative nos
        }
        
        return cnt;
    }
};