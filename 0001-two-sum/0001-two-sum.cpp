class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        int n= nums.size();
        

        // the intuitive / brute force appraoch: TIME & SPACE O(n^2), O(1) 
        // for every index i, we will check every other index to its right if their sum== target

        // 2nd approach: hashmap so space= O(n) and time = O(n)
        // for every value, we will check in our map if a value = (target - curr_val) exists or not
        // if yes, we will send both their indices
        // if not, store the mapping of current value -> to its index

        vector<int> ans;
        for( int i=0; i<n;i++){
            if( mp.find(target-nums[i]) != mp.end()){
                ans = { mp[ target - nums[i]] , i };
                break;
            }
            else
                mp[ nums[i]] = i;
        }
        return ans;
    }
};