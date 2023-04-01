class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l = 0, r= n-1, mid;
        while( l<= r){
            int mid= (l+r)/2;
            if( nums[mid] == target)
                return mid;
            // if( l==r )
            //     return -1;
            
            if( nums[mid] < target)
                l= mid+1;
            else
                r=mid-1;
        }
        return -1;
        
    }
};