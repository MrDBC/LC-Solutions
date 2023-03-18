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
    int dfs( int n, int a, int b, int c){
        if( n==0)
            return 1;
        
        if( a!=-1 and dp[n][a][b][c] != -1){
            return dp[n][a][b][c];
            cout<<a<<b<<c<<endl;
        }
        
        
        int ways = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                for(int k=0; k<3; k++){
                    if( i==a || j==b || k==c)
                        continue;
                    if( i==j || j==k)
                        continue;
                    
                    
                    ways =(ways + dfs(n-1, i,j,k))%mod;
                }
            }
        }
        
        if( a!= -1)
            return dp[n][a][b][c] = ways;
        else
            return ways;
    }
};