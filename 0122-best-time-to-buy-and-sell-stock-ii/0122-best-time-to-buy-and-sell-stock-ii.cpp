class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        
        //        ( prices, index, canbuy, dp)
        return dfs( prices, 0, true, dp);
    }
    int dfs( vector<int>& prices, int idx, bool canbuy, vector<vector<int>>& dp){
        if( idx== prices.size())
            return 0;
        if( dp[idx][canbuy] != -1)
            return dp[idx][canbuy];
        
        if(canbuy){ /// ie. we have option of buying, not selling
            // 2 choices: buy current day stock or dont
            return dp[idx][canbuy]= max( -prices[idx]+ dfs(prices,idx+1, !canbuy, dp), dfs(prices, idx+1, canbuy, dp));
        }
        else{ // we can sell and not buy, becoz we already have a stock with us
            return dp[idx][canbuy]= max(prices[idx]+ dfs(prices, idx+1, !canbuy, dp), dfs(prices, idx+1, canbuy,dp));
        }
    }
};