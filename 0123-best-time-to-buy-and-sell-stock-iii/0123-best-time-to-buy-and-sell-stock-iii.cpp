class Solution {
    int dp[100000+1][2][4+1];
public:
    int maxProfit(vector<int>& prices) {
        
        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(4+1, -1)));
        memset(dp, -1, sizeof(dp));
        int n = prices.size();
        
        return dfs(prices, 0, 1, 4);
    }
        
    int dfs(vector<int>& prices, int idx, int canbuy, int transactionsLeft ){
       if( prices.size() == idx)
            return 0;
        if( transactionsLeft==0 )
            return 0;
        if( dp[idx][canbuy][transactionsLeft] != -1)
            return dp[idx][canbuy][transactionsLeft];
        
        
        if(canbuy )/// ie. we have option of buying, not selling
            // 2 choices: buy current day stock or dont
            return dp[idx][canbuy][transactionsLeft]= max( -prices[idx]+ dfs(prices, idx+1, !canbuy, transactionsLeft-1 ), dfs(prices, idx+1, canbuy, transactionsLeft));

        else // we can sell and not buy, becoz we already have a stock with us
            return  dp[idx][canbuy][transactionsLeft]= max(prices[idx]+ dfs(prices, idx+1, !canbuy, transactionsLeft-1 ), dfs(prices, idx+1, canbuy, transactionsLeft));
        
       
       
    }
};