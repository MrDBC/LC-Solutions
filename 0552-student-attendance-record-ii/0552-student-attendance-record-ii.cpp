class Solution {
    int dp[100001][2][3];
    int mod = 1e9+7;
public:
    int checkRecord(int n) {
        
        memset(dp, -1, sizeof(dp));
        // total spaces to fill, no of absent, no of consecutive lates
        return dfs( n, 0, 0 );
    }
    
    int dfs( int n, int total_absents, int consecutive_lates){
        
        // if we reached this point, that means we have found 1 valid way to arrange (A,P,L)
        if( n==0)
            return 1;
        
        if( dp[n][total_absents][consecutive_lates] != -1)
            return dp[n][total_absents][consecutive_lates];
        
        int total_ways=0;
        // add (A) only if condition permits
        // now if we add a (A), our consecutive lates will be reset to 0
        if( total_absents <1){
            total_ways = (total_ways+ dfs( n-1, total_absents+1,0))%mod;
        }
        
        // add (L) only if condition permits
        if( consecutive_lates <2)
            total_ways = (total_ways+ dfs(n-1, total_absents, consecutive_lates+1))%mod;
        
        // but u can add (P) literally anytime , anycount
        // now if we add a (P), our consecutive lates will be reset to 0
        total_ways = (total_ways+ dfs(n-1, total_absents, 0))%mod;
        
        return dp[n][total_absents][consecutive_lates] = total_ways;
    }
};