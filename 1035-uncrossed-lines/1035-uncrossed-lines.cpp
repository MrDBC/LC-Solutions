class Solution {
    int dp[501][501];
public:
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        int m= a.size(), n= b.size();
        
        memset(dp, -1, sizeof(dp));
        return dfs(a, b, m, n);
    }
    int dfs(vector<int>& a, vector<int>& b, int m, int n){
        if( !m or !n)
            return 0;
        
        if( dp[m][n] != -1)
            return dp[m][n];
        
        int match =0, unmatch=0;
        if( a[m-1] == b[n-1])
            match = 1+ dfs(a, b, m-1, n-1);
        
        unmatch = max( dfs(a, b, m-1, n), dfs(a, b, m, n-1));
        
        
        return dp[m][n]= max( match, unmatch);
    }
};