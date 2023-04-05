class Solution {
public:
    int isvalid(vector<int>& numsorig, int target){
        int n= numsorig.size();
        vector<long> nums(numsorig.begin(), numsorig.end());
      
        for(int i=n-1; i>=1; i--){
            if( nums[i] > target)
                nums[i-1]+= nums[i] - target;
        }
        
        return nums[0]<=target;
        
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n= nums.size();
       
        int l=0, r= *max_element(begin(nums), end(nums)), ans=*max_element(begin(nums), end(nums));
        while ( l<=r){
            int mid = l+(r-l)/2;
            
            if( isvalid(nums, mid)){
                ans= mid;
                r = mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};