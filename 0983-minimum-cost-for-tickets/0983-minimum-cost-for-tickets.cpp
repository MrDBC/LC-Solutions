class Solution {
    int dp[365];
public:
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n= days.size();
        memset(dp, -1, sizeof(dp));
        return dfs(days, 0, n, costs);
    }
    
    int dfs(vector<int>& days, int idx  , int n, vector<int>& costs ){
        if( idx>=n)
            return 0;
        
        if( dp[idx] != -1)
            return dp[idx];
        int mincost = INT_MAX;
        for(int i=0; i<3; i++){
            int start_day = days[idx];
            int end_day = start_day + ((i==0)? 0: ((i==1)? 6 : 29 ));
            
            int k;
            for( k= idx; k<n; k++){
                int curr_day = days[k];
                
                if( curr_day> end_day)
                    break;
            }
            
            // take a one day pass, 7 day pass or 30 day pass and do recursive calls
            if( i==0)
                mincost = min(mincost, costs[0] + dfs(days, k , n, costs));
            else if( i==1)
                mincost = min(mincost, costs[1] + dfs(days, k , n, costs));
            else 
                mincost = min(mincost, costs[2] + dfs(days, k , n, costs));
      
      
        }
        
        return dp[idx]= mincost;
    }
};