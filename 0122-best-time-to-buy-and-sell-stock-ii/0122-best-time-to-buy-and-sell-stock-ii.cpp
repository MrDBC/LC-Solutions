class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        int n = prices.size();
        
        dp[n-1][0]= prices[n-1];
        for(int idx=n-2; idx>=0 ; idx--){
            for(int canbuy=1; canbuy>=0; canbuy--){
                if(canbuy)/// ie. we have option of buying, not selling
                    // 2 choices: buy current day stock or dont
                    dp[idx][canbuy]= max( -prices[idx]+ dp[idx+1][ !canbuy] , dp[idx+1][canbuy]);

                else // we can sell and not buy, becoz we already have a stock with us
                    dp[idx][canbuy]= max(prices[idx]+  dp[idx+1][ !canbuy] , dp[idx+1][canbuy]);
            }
        }
        
        return dp[0][1];
        
       
    }
};