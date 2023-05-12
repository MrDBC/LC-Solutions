class Solution {
    long long dp[100001];
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n= questions.size();
        
        memset(dp, -1, sizeof(dp));
        
        return dfs(questions, 0, n);
    }
    
    long long dfs(vector<vector<int>>& questions,int idx,  int n){
        if( idx>=n)
            return 0;
        
        if( dp[idx] != -1)
            return dp[idx];
        
        long long take_it=0, dont_take_it=0;
        
        take_it= questions[idx][0] + dfs(questions, idx+questions[idx][1]+1, n);
        dont_take_it = dfs(questions, idx+1, n);
        
        return dp[idx]= max( take_it, dont_take_it);
    }
};