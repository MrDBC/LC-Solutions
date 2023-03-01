class Solution {
public:
// recursion + dp (top-down)= no TLE
    int findLongestChain(vector<vector<int>>& pairs) {
        int n= pairs.size();
        sort(begin(pairs), end(pairs));
        
        vector<int> dp(n+1, -1);
        return dfs(pairs, n, 1001, dp);

    }
    int dfs( vector<vector<int>>& pairs, int n, int next_first, vector<int>& dp){
        if( n==0)
            return 0;
        if( dp[n-1] != -1)
            return dp[n-1];

        int curr_first= pairs[n-1][0];
        int curr_end=pairs[n-1][1];
        int choice=0, no_choice=0;

        if( curr_end < next_first){
            choice= max( 1+ dfs(pairs, n-1, curr_first, dp), dfs(pairs, n-1, next_first, dp));
        }
        else
            no_choice = dfs(pairs, n-1, next_first, dp);

        return dp[n-1] =max( choice, no_choice);
    }
};