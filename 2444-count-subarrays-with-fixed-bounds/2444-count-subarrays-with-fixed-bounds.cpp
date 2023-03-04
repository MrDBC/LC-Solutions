class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n= nums.size();
        
        // this looks like a pointer approach: 
        // ok so here's the intuition:
        // we will have 3 pointers: 
        // 1. left_out_of_bound_idx, 
        // 2. recent_mink_idx, 
        // 3. recent_max_idx
        // and we can apply the simple formula at each index i
        // count+= max(0, min(recent_mink_idx,recent_max_idx) - left_out_of_bound_idx)
        
        int left_out_of_bound_idx=-1;
        int recent_minK_idx = -1; 
        int recent_maxK_idx = -1;
        long int cnt =0;
        
        for(int i=0; i<n; i++){
            // checK if nums[i] is within range
            if( nums[i]>=minK && nums[i]<=maxK){
                // update the recent_minK_idx & recent_max_idx and count as well
                recent_minK_idx = (nums[i]==minK)? i: recent_minK_idx;
                recent_maxK_idx = (nums[i]==maxK)? i: recent_maxK_idx;
                
                cnt+= max(0, min(recent_minK_idx, recent_maxK_idx) - left_out_of_bound_idx);
            }
            else
                left_out_of_bound_idx = i;
        }
        
        return cnt;
        
    }
};