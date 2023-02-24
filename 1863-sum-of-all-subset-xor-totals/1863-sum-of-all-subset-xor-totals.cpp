class Solution {
    int sum=0;
public:
    int subsetXORSum(vector<int>& nums) {
        int xorr=0;

        dfs( nums, 0, xorr);
        return sum;
    }
    void dfs(vector<int>& nums, int idx , int xorr){
        sum+= xorr; 
        if( idx== nums.size())
            return;

        // [], [5] [5,1] [5,1,6] [5,6] [6]
        for(int i=idx; i<nums.size(); i++)
            dfs(nums, i+1, xorr^nums[i]);
    }
};