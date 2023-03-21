class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n= nums.size();

        set<int> s(nums.begin(),nums.end());
        // 0 1 3 5 
        
        return (*s.begin() ==0 )? s.size()-1 : s.size();
    }
};