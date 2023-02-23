class Solution {
    int dp[1000][2][(100*2)+1];
public:
    int maxProfit(int k, vector<int>& prices) {
        
        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(4+1, -1)));
        memset(dp, -1, sizeof(dp));
        int n = prices.size();
        
        // my definition of transaction :
        // 1 buy = 1 transaction
        // 1 sell = 1 transaction
        // since its given we can do at most k transactions: it means we can buy k times  & sell k times 
        // so at most (2*k) transactions

        //        (prices, index, we have to buy ist, so canbuy=1 ,no of transactions we can do)
        return dfs(prices, 0, 1, 2*k);
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