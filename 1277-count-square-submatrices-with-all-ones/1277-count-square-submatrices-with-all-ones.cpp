class Solution {
    int dp[301][301];
public:
    int countSquares(vector<vector<int>>& matrix) {
        int cnt=0;
        int m= matrix.size(), n= matrix[0].size();
        
        memset(dp, -1, sizeof( dp));
        
        for(int i=0; i<m;i ++)
            for(int j=0; j<n; j++)
                cnt+= dfs(i,j,matrix);
        
        return cnt;
    }
    
    // dp[i][j] = maximum length of square with bottom-right vertex at matrix[i][j]
    int dfs( int i, int j, vector<vector<int>>& matrix){
        int m= matrix.size(), n= matrix[0].size();
        
        if( dp[i][j] != -1)
            return dp[i][j];
        
        if( matrix[i][j] == 1){
            if( i and j)
                dp[i][j]= 1+min( dfs(i-1, j-1, matrix), min( dfs( i-1, j, matrix), dfs( i, j-1, matrix)));
            else
                dp[i][j]= 1;
        }
        else
            dp[i][j]=0;
    
        return dp[i][j];
    }
};