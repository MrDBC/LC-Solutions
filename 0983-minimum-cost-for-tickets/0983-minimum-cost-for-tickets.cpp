class Solution {
    unordered_set<int> setdays;
    int dp[365+1];
    // dp[d] indicates the min. cost to travel among the dates
    // lying b/w [1 to d]
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(auto d: days)
            setdays.insert(d);
        
        memset(dp, -1, sizeof(dp));
        return dfs(1,costs );
    }
    int dfs(int starting_day, vector<int>& costs){
        if( starting_day>365)
            return 0;
        
        if( dp[starting_day] != -1)
            return dp[starting_day];

        // 3 choices: 1 , 7 or 30 day pass
        int cost1=INT_MAX, cost7= INT_MAX, cost30= INT_MAX;
        
        // if we have plan for this particular day, pay
        // and recursively find the rest of the cost
        if( setdays.find(starting_day) != setdays.end())
            cost1= costs[0] + dfs(starting_day+1, costs);
        
        // if we dont have plan for this particular day,
        // just recursively find for the days lying b/w
        // [starting_day+1 to 365]
        if( cost1 == INT_MAX)
            cost1 = dfs(starting_day+1, costs);
        
        // basically if we have a plan to travel in any of
        // the days b/w [starting_day to starting_day+6]
        // we will pay for a 7day pass, and recursively find 
        // the cost for days b/w [starting_day+7  to 365]
        for(int i=0; i<7; i++){
            int curr_day= starting_day+i;
            if( setdays.find(curr_day) != setdays.end()){
                cost7= costs[1] + dfs(starting_day+7, costs);
                break;
            }
        }
        // this indicates we dont have any plan to travel on
        // days lying b/w [starting_day to starting_day+6] 
        // we dont buy the pass and recursively find for the
        // days b/w [starting_day+7 to 365]
        if( cost7==INT_MAX)
            cost7=  dfs(starting_day+7, costs);
        
        // similar logic with a 30 day pass as well
        for(int i=0; i<30; i++){
            int curr_day= starting_day+i;
            if( setdays.find(curr_day) != setdays.end()){
                cost30= costs[2] + dfs(starting_day+30, costs);
                break;
            }
        }
        if( cost30 ==INT_MAX)
            cost30 =  dfs(starting_day+30, costs);
        
        return dp[starting_day]= min(cost1, min(cost7, cost30));
      
    }
};