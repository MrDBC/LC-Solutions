class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n= nums.size();
        
        int prefixxor = 0;
        for(auto num: nums)
            prefixxor^= num;
        
        vector<int> ans(n);
        int target = (1<<maximumBit) -1;
        
        for(int i=0; i<n; i++){
            ans[i] = prefixxor ^ target;
            
            prefixxor^= nums[n-i-1];
        }
        
        return ans;
    }
};