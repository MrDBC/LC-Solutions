class Solution {
  
public:
    int maxProfit(vector<int>& prices) {
        
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(4+1, -1)));
        int n = prices.size();
        
        return dfs(prices, 0, 1, 4, dp);
    }
        
    int dfs(vector<int>& prices, int idx, int canbuy, int transactionsLeft, vector<vector<vector<int>>>& dp){
       if( prices.size() == idx)
            return 0;
        if( transactionsLeft==0 )
            return 0;
        if( dp[idx][canbuy][transactionsLeft] != -1)
            return dp[idx][canbuy][transactionsLeft];
        
        
        if(canbuy )/// ie. we have option of buying, not selling
            // 2 choices: buy current day stock or dont
            return dp[idx][canbuy][transactionsLeft]= max( -prices[idx]+ dfs(prices, idx+1, !canbuy, transactionsLeft-1 , dp), dfs(prices, idx+1, canbuy, transactionsLeft, dp));

        else // we can sell and not buy, becoz we already have a stock with us
            return  dp[idx][canbuy][transactionsLeft]= max(prices[idx]+ dfs(prices, idx+1, !canbuy, transactionsLeft-1 , dp), dfs(prices, idx+1, canbuy, transactionsLeft, dp));
        
       
       
    }
};