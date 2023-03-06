class Solution {
    int dp[101];
public:
    int rob(vector<int>& nums) {
        
        // 100 11 10 1000
        // odd - 110 even =1011
        // 1100
        
        int n= nums.size();
        memset(dp, -1, sizeof(dp));
        return dfs(nums, n);
    }
    
    int dfs( vector<int>& nums, int n){
        if( n<=0)
            return 0;
        if( dp[n] != -1)
            return dp[n];
        
        int robCurrentHouse = nums[n-1] + dfs(nums, n-2);
        int dontRobCurrentHouse = dfs(nums, n-1);
        
        return dp[n]=max(robCurrentHouse, dontRobCurrentHouse);
        
    }
};