class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n+1,vector<int>(3, -1));

        return dfs(nums, n, 0, dp) ;
    }

    int dfs( vector<int>& nums, int i, int rem, vector<vector<int>> &dp){
        if( i==0){
            if(rem==0)
                return 0;
            else
                return INT_MIN+1000;
        }
        if( dp[i][rem] != -1)
            return dp[i][rem];

        int take = nums[i-1] + dfs(nums, i-1, (rem+nums[i-1])%3, dp);
        int dont = dfs(nums, i-1, rem, dp);

        return dp[i][rem] = max(take, dont );
        
    }
};