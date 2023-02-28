class Solution {
    int dp[201][201];
public:
    int dfs(vector<vector<int>>& dungeon, int i, int j) {
        int m= dungeon.size(), n= dungeon[0].size();
        
        if(i==m or j==n )
            return INT_MAX-1;
        
        int curr_health = dungeon[i][j];
        
        if( i==m-1 and j==n-1)
            return 1+ ((curr_health<0)? abs(curr_health) : 0);
        
        if( dp[i][j] != -1)
            return dp[i][j];

        int right_need = dfs(dungeon, i, j+1);
        int down_need = dfs(dungeon, i+1, j);
        int next_need = min( right_need, down_need);

        // if curr_health is already greater than next need, we just need minimum health =1,
        // to reach current cell = dungeon[i][j]
        if( curr_health >= next_need)
            return dp[i][j]= 1;

        // else if curr_health is less than next_need, we need to enter the current cell = dungeon[i][j],
        // with extra health ;
        // with atleast the shortage of health = (next_need - curr_health);
        // for eg: ( also note the next_need is always positive, atleast = 1)
        // case 1: if curr_health = 3 and we need 5 to jump from current cell to next optimal cell,
        //         then we need to enter the current cell with atleast (5-3)= 2 health
        // case 2: if curr_health = -10, and we need 5 to jump from current cell to next optimal cell,
        //         we need to enter the current cell with atleast (5-(-10))=15 health
        else
            return dp[i][j]=  (next_need- curr_health);
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp, -1, sizeof(dp));
        return dfs( dungeon, 0, 0);
    }
};