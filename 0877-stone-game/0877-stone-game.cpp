class Solution {
public:
    // no TLE (RECURSION + memo): TC: O(n*n) SC: O(n) call stack
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        int total =0;
        for(auto i: piles)
            total+= i;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        if( dfs(piles, 0, n-1, dp) >= (total+1)/2 )
            return 1;
        else
            return 0;
    }
    
    int dfs(vector<int>& piles, int front , int end, vector<vector<int>>& dp){
        if( front > end  )
            return 0;
        
        if( dp[front][end] != -1)
            return dp[front][end];
            
        // if total no. of piles left is even, its alice turn
        int turn = (end-front+1);
        int take_left=0, take_right=0;
        
        if( turn%2==0){ // alice turn
            take_left = piles[front] +dfs(piles, front+1, end, dp);
            take_right = piles[end] + dfs(piles, front, end-1, dp);
        }
        else{ // bob turn
            take_left =  dfs(piles, front+1, end, dp);
            take_right = dfs(piles, front, end-1, dp);
        }
        
        return dp[front][end]= max( take_left , take_right);
        
    }
};