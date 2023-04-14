class Solution {
    int dp[1001][1001];
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        
        memset(dp, -1, sizeof(dp));
        
        string rev= s;
        reverse(begin(rev), end(rev));
        return dfs( s, rev, n, n);
    }
    int dfs(string& s, string& rev, int i, int j){
        if( !i or !j)
            return 0;
        
        if( dp[i][j] != -1)
            return dp[i][j];
        
        int take =0, dontake =0;
        if( s[i-1] == rev[j-1])
            take = 1 + dfs( s, rev, i-1, j-1);
        else
            dontake = max( dfs(s, rev, i, j-1), dfs( s, rev, i-1,j ));
        
        return dp[i][j]= max( take , dontake);
    }
};