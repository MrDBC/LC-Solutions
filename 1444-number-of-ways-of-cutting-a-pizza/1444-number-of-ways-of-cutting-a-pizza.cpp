class Solution {
    int mod= 1e9+7;
    int dp[11][51][51];
public:
    
    // the recursive code: 52 / 53 test cases passed.
    int ways(vector<string>& pizza, int k) {
        int m= pizza.size(), n= pizza[0].size();
        memset(dp, -1, sizeof(dp));
        
        return dfs(pizza, k-1, 0, 0);
    }
    int checkapple( vector<string>& pizza, int a, int b, int c, int d){
        for(int i=a; i<=b; i++)
            for(int j=c; j<=d; j++)
                if( pizza[i][j] == 'A')
                    return 1;
        return 0;
    }
    int dfs(vector<string>& pizza, int cuts, int rowstart, int colstart){
        int m= pizza.size(), n= pizza[0].size();
        
        bool apples_left = checkapple(pizza, rowstart, m-1, colstart, n-1);

        if( cuts==0)
            return apples_left== true;
        
        if( dp[cuts][rowstart][colstart] != -1)
            return dp[cuts][rowstart][colstart];
        
        /// horizontal cutting
        int horizontalcuts=0;
        for(int r=rowstart; r< m-1; r++)
            if( checkapple(pizza, rowstart, r, colstart, n-1))
                horizontalcuts= (horizontalcuts + dfs(pizza, cuts-1, r+1, colstart))%mod;
            
        // vertical cutting
        int verticalcuts=0;
        for(int c=colstart; c< n-1; c++)
            if( checkapple(pizza, rowstart, m-1, colstart, c))
                verticalcuts= (verticalcuts + dfs(pizza, cuts-1, rowstart, c+1))%mod;
        
        
        return dp[cuts][rowstart][colstart]= (horizontalcuts + verticalcuts )%mod;
    }
};