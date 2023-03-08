class Solution {
    int dp[365+1];
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n= days.size();
        memset(dp, 0, sizeof(dp));
        
        // 1 2 3 4 5 6 7 8
        unordered_set<int> travelDays(begin(days), end(days));
        for(int day=1; day<=365; day++){
            if( travelDays.count(day)){
                dp[day]= min( costs[0] + dp[day-1], min(
                                costs[1] + (day>=7? dp[day-7] : 0), 
                                costs[2] + (day>=30? dp[day-30] : 0)));
            }
            else
                dp[day]= dp[day-1];
        }
        
        return dp[365];
        
    }
};