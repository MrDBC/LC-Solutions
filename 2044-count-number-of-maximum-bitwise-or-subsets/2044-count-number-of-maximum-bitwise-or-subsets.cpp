class Solution {
    int max_or=0, max_orcnt=0;
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n= nums.size();
        
        vector<int> dp(n+1, -1);
        
        dfs( nums, n,0);
        return max_orcnt;
    }
    void dfs(vector<int>& nums, int n, int or_tillnow){
        if( n==0){
            if( max_or == or_tillnow){
                max_orcnt++;
            }
            else if(max_or < or_tillnow){
                max_or = or_tillnow;
                max_orcnt=1;
            }
            return;
        }
        
        dfs(nums, n-1, (or_tillnow | nums[n-1]));
        dfs( nums, n-1, or_tillnow);
        
        
    }
};