class Solution {
    int mod= 1e9+7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp(high+1, -1);
        dp[0]=1;
        
        // for(int i=1; i<=high; i++){
        //     if( i-zero>=0)
        //         dp[i] = (dp[i] + dp[i-zero])%mod;
        //     if( i-one>=0)
        //         dp[i]= (dp[i] + dp[i-one])%mod;

        // }
        int ans=0;
        for(int i=low; i<=high; i++)
            ans=(ans + dfs(i, zero, one, dp))%mod;
        
        return ans;   
    }
    int dfs(int left, int zero, int one, vector<int>& dp){
        if( left==0)
            return 1;
        

        if( dp[left]!= -1)
            return dp[left];

        int append0=0, append1=0;
        // append 0s
        if( left>= zero)
            append0=dfs(left-zero, zero, one,dp);

        // append 1s
        if( left>=one)
            append1=dfs(left-one, zero, one, dp);

        return dp[left]= (append0 + append1)%mod;
    }
};