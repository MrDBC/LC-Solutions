class Solution {
    int dp[301][301];
public:
    int countSquares(vector<vector<int>>& matrix) {
        int cnt=0;
        int m= matrix.size(), n= matrix[0].size();
        
        memset(dp, 0, sizeof( dp));
        
        for(int i=1; i<=m;i ++)
            for(int j=1; j<=n; j++){
                if( matrix[i-1][j-1])
                    dp[i][j]= 1+min( dp[i-1][j-1], min( dp[i][j-1], dp[i-1][j]));
                cnt+= dp[i][j];
            }
        return cnt;
    }
    
    // dp[i][j] = maximum length of square with bottom-right vertex at (i,j)
    
};