class Solution {
    unordered_set<int> setdays;
    int dp[365+1];
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(auto d: days)
            setdays.insert(d);
        
        memset(dp, -1, sizeof(dp));
        return dfs(1,costs );
    }
    int dfs(int curr_day, vector<int>& costs){
        if( curr_day>365)
            return 0;
        
        if( dp[curr_day] != -1)
            return dp[curr_day];
        // 3 choices: 1 , 7 or 30 day pass
        int cost1=INT_MAX, cost7= INT_MAX, cost30= INT_MAX;
        if( setdays.find(curr_day) != setdays.end())
            cost1= costs[0] + dfs(curr_day+1, costs);
        else
            cost1 = dfs(curr_day+1, costs);
        
        for(int i=0; i<7; i++){
            int day= curr_day+i;
            if( setdays.find(day) != setdays.end()){
                cost7= costs[1] + dfs(curr_day+7, costs);
                break;
            }
        }
        if( cost7==INT_MAX)
            cost7=  dfs(curr_day+7, costs);
        
        
        for(int i=0; i<30; i++){
            int day= curr_day+i;
            if( setdays.find(day) != setdays.end()){
                cost30= costs[2] + dfs(curr_day+30, costs);
                break;
            }
        }
        if( cost30 ==INT_MAX)
            cost30 =  dfs(curr_day+30, costs);
        
        return dp[curr_day]= min(cost1, min(cost7, cost30));
        // if( mincost ==INT_MAX)
        //     return dfs(curr_day+30, costs);
        // return mincost;
            
    }
};