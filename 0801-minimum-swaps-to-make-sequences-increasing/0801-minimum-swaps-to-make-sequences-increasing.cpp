class Solution {
    vector<vector<int>>dp;
    int getMin(vector<int>&nums1,vector<int>&nums2,int idx,bool flag){
        if(idx == nums1.size())
            return 0;
        
        if(dp[idx][flag] != -1)return dp[idx][flag];
        
        int prev1 = (flag)?nums2[idx - 1]: nums1[idx - 1];
        int prev2 = (flag)?nums1[idx - 1]: nums2[idx - 1];
        
        int minscore = INT_MAX;
        if(nums2[idx] > prev1 && nums1[idx] > prev2)
            minscore = min(minscore, 1 + getMin(nums1, nums2, idx + 1, true));
        
        if(nums2[idx] > prev2 && nums1[idx] > prev1)
            minscore = min(minscore, getMin(nums1, nums2, idx + 1, false));
        
        return dp[idx][flag] = minscore;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(),vector<int>(2,-1));
        
        int temp1 = getMin(nums1, nums2, 1, false);
        int temp2 = 1 + getMin(nums1, nums2, 1, true);
        
        return min(temp1, temp2);
    }
};