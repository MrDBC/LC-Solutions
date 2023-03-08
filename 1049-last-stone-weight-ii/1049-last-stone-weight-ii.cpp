class Solution {
    vector<vector<int>> dp;
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n= stones.size();
        sort(begin(stones), end(stones));
    
        // range of sum can be +- ( 30*100)
        // so total types of sum= 2*( 30*100)   + 1(for safety)
        dp.resize(n+1, vector<int>(6000+1, -1));
        
        // 1 1 2 4 7 8
        return dfs(stones, n);
    }
    int dfs(vector<int>& stones, int n, int sum=0 ){
        if( n==0)
            return (sum<0)?100: sum; // we dont want to choose negative sum 
        
        // our sum can be negative, but we cant have negative indices
        // so we need a uniform formula for converting those negative
        // sums to positive
        // we know the minimum sum = -(30*100) or more specifically -(stones.size() * 100 )
        
        int mod_sum = sum+ (stones.size()* 100);
        if( dp[n][mod_sum] != -1)
            return dp[n][mod_sum];
        
        int pos= dfs(stones, n-1, sum+ stones[n-1]);
        int neg =  dfs(stones,n-1, sum -stones[n-1]);
        
        return dp[n][mod_sum]=min( pos, neg);
    }
};