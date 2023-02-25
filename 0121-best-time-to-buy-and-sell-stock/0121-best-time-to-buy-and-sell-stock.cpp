class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxprofit=0;
        int minPricesofar = INT_MAX;

        int n = prices.size();
        for(int i=0 ; i<n; i++){
            minPricesofar = min( minPricesofar, prices[i]);
            maxprofit = max(maxprofit, prices[i] - minPricesofar);
        }

        return maxprofit;
    }
};