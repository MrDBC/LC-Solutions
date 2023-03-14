typedef long long ll;
class Solution {
    int mod= 1e9+7;
    int maxprod=-1;
    // minmaxprod[i][j][0] gives min product from grid[i][j] to bottom right cell
    // minmaxprod[i][j][1] gives max. product from grid[i][j] to bottom right cell
    vector<vector<vector<ll>>> minmaxprod;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m= grid.size();
        int n = grid[0].size();
        
        minmaxprod.resize(m,vector<vector<ll>>(n,vector<ll> (2)));
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                minmaxprod[i][j] = {LLONG_MIN,LLONG_MAX};
            }
        }
        
        vector<ll> ans = dfs( 0,0, grid);
        if( ans[1]<0)
            return -1;
        else
            return ans[1]%mod;
        
    }
    vector<ll>  dfs( int i, int j, vector<vector<int>>& grid){
        int m= grid.size();
        int n = grid[0].size();
        
        if( i==m-1 and j==n-1){
            return {grid[i][j], grid[i][j]};
        }
        
        if( minmaxprod[i][j][0] != LLONG_MIN && minmaxprod[i][j][0] != LLONG_MAX)
            return minmaxprod[i][j];
        
        ll maxprod = LLONG_MIN, minprod = LLONG_MAX;
        if( (i+1)<m){
            vector<ll> prodfromdown = dfs(i+1, j, grid);
            minprod = min({minprod, grid[i][j] * prodfromdown[0], grid[i][j] * prodfromdown[1]});
            maxprod = max( {maxprod, grid[i][j] * prodfromdown[0], grid[i][j] * prodfromdown[1]});
        }
        if( j+1<n){
            vector<ll> prodfromright = dfs(i, j+1, grid);
            minprod = min({minprod, grid[i][j] * prodfromright[0], grid[i][j] * prodfromright[1]});
            maxprod = max( {maxprod, grid[i][j] * prodfromright[0], grid[i][j] * prodfromright[1]});
        }
        
        return  minmaxprod[i][j]= { minprod, maxprod};
        
    }
    
};