class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n= nums.size();
        int total_score=0;
        for(auto e: nums)
            total_score+= e;
        
        return dfs(nums,0,n-1)>= (total_score+1)/2;
    }
    
    int dfs(vector<int>& nums, int l, int r){
        if( l>r)
            return 0;
        
        int take_left = nums[l] + min(dfs(nums,l+2,r), dfs(nums, l+1, r-1));
        int take_right = nums[r] + min(dfs(nums,l+1,r-1), dfs(nums,l, r-2));
        
        return max(take_left, take_right);
    }
};