class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int l=0 , r=nums.size()-1;
        while( l<r){
            int mid= (l+r)/2;
            if( nums[mid] == target)
                return mid;
            else if( nums[mid] < target)
                l=mid+1;
            else
                r=mid;
        }
        return target>nums[l]? l+1: l;

        // auto pos = lower_bound(nums.begin(), nums.end(), target);
        // return pos-nums.begin();
    }
};