class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n= nums.size();
        
        // maximum diff = 500 - 0 = 500
        // minnimum difference we could get = (0 - 500)= -500
        // so we add 500 to avoid negative indices in the vector
        // so total size = 500 + 500 + 1( for safety)
        
        vector<vector<int>>  dp(n+1, vector<int>(1000+1, 1));
        
        int res=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int diff = (nums[i]- nums[j]) + 500; // to avoid negative differences
                
                
                // arithmetic subseq length = 2, when we only take {nums[j], nums[i]}
                // in our AP
                dp[i][diff] = max( 2, 1 + dp[j][diff]);
                res = max( res, dp[i][diff]);
            }
        }
        
        return res;
        
    }
};