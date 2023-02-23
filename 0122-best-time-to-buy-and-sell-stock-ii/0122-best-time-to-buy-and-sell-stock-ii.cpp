class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit= 0;
        
        int prevprice = prices[0], n = prices.size();
        for(int i=1; i<n; i++){
            
            if( prevprice< prices[i])
                maxprofit+= prices[i]-prevprice;
            
            prevprice= prices[i];
        }
        
        return maxprofit;
    }
};