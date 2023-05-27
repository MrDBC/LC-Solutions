class Solution {
    
public:
    string stoneGameIII(vector<int>& val) {
        int n= val.size();
        
        vector<int> dp(n, -1);
        
        int alicegetsmore = dfs(val, 0, dp);
        
        return (alicegetsmore==0)? "Tie": (alicegetsmore > 0)? "Alice": "Bob";
    }
    
    int dfs(vector<int>& val, int idx, vector<int>& dp){
        
        int n = val.size();
        if( idx==n)
            return 0;
        
        if( dp[idx] != -1)
            return dp[idx];
        
        
        int optstonetake=0, maxvalucanget= INT_MIN;
        for(int i=idx; i<= min(n-1, idx+2); i++){
            optstonetake+= val[i];
            
            maxvalucanget= max( maxvalucanget, optstonetake - dfs(val, i+1, dp));
        }
        
        return dp[idx]= maxvalucanget;
    }
};