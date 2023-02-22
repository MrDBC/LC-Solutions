class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n= nums.size();
        int total_score=0;
        for(auto e: nums)
            total_score+= e;
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(nums,0,n-1, dp)>= (total_score+1)/2;
    }
    
    int dfs(vector<int>& nums, int l, int r,vector<vector<int>>& dp ){
        if( l>r)
            return 0;
        if( dp[l][r] != -1)
            return dp[l][r];
        
        int take_left = nums[l] + min(dfs(nums,l+2,r, dp), dfs(nums, l+1, r-1, dp));
        int take_right = nums[r] + min(dfs(nums,l+1,r-1, dp), dfs(nums,l, r-2, dp));
        
        return dp[l][r]= max(take_left, take_right);
    }
};