class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorr=0;
        for(auto i: nums)
            xorr^= i;
        
        return xorr;
    }
};