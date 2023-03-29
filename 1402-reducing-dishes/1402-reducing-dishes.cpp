class Solution {
    int dp[501][501];
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(begin(sat), end(sat));
        
        memset(dp, -1 , sizeof(dp));
     
        return dfs(sat, 0, 1);
    }
    int dfs( vector<int>& sat, int idx, int cnt){
        if( idx==sat.size())
            return 0;
        
        if( dp[idx][cnt] != -1)
            return dp[idx][cnt];
        // take it or dont
        int takeit = sat[idx]*cnt + dfs(sat, idx+1, cnt+1);
        int dont = dfs(sat, idx+1, cnt);
        
        return dp[idx][cnt]= max(takeit, dont);
    }
};