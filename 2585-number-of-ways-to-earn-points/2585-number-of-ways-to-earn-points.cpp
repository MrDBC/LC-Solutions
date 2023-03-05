class Solution {
public:

long long dp[51][1001] = {};
long long mod = 1e9 + 7;

int waysToReachTarget(int target, vector<vector<int>>& types) {
    memset(dp, -1, sizeof(dp));
    long long ans = rec(types, target, 0);
    return ans % mod;
}

long long rec(vector<vector<int>>& nums, int sum, int i) {
    
    if(sum < 0) return 0;
    if(sum == 0) return 1;
    if(i == nums.size()) return 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    
    long long tmp = 0;
    
    for(int j = 0 ; j <= nums[i][0] ; j++) {
        long long s = sum - j * nums[i][1];
        if(s < 0) break;
        if(s == 0) {
            tmp++; break;
        }
        tmp = (tmp + rec(nums, s, i + 1)) % mod;
    }
    
    dp[i][sum] = tmp;
    return tmp;
}
};