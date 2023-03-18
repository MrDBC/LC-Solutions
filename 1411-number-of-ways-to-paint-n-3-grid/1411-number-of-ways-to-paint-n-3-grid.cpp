class Solution {
    int dp[5001][3][3][3];
    int mod= 1e9+7;
public:
    // red: 0, yellow: 1, green: 2
    int numOfWays(int n) {
        memset(dp, -1,sizeof(dp));
        
        return dfs(n, -1, -1, -1);
    }
    // a,b,c are the color of ist, 2nd & 3rd col in (n+1)th row
    
    // dfs(n, a, b, c)= the number of ways to color ist n rows of the grid
    // keeping in mind that the next row (n + 1) has colors a, b and c
    int dfs( int n, int a, int b, int c){
        if( n==0)
            return 1;
        
        
        if( a!=-1 and dp[n][a][b][c] != -1)
            return dp[n][a][b][c];
            
        int ways = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                for(int k=0; k<3; k++){
                    // ist cell of nth row cant be same as ist cell of (n+1)th row
                    // similarly for 2nd cell & 3rd cells
                    if( i==a || j==b || k==c)
                        continue;
                    // ist 2 cells of current nth row cant be same
                    // also last 2 cells of current nth row cant be same
                    if( i==j || j==k)
                        continue;
                    
                    
                    ways =(ways + dfs(n-1, i,j,k))%mod;
                }
            }
        }
        
        // edge case for the non-existent (n+1)th cell
        if( a== -1)
            return  ways;
        else
            return dp[n][a][b][c] = ways;
    }
};