class Solution {
    int mod= 1e9+7;
    unordered_map<int, vector<int>> nextMove;
    int dp[50001][10];
public:
    int knightDialer(int n) {
        // 2 states are changing: n & which numeric cell
        
        memset(dp, -1, sizeof(dp));
        
        nextMove[0]= vector<int>{4,6};
        nextMove[1]= vector<int>{8,6};
        nextMove[2]= vector<int>{7,9};
        nextMove[3]= vector<int>{4,8};
        nextMove[4]= vector<int>{0,3,9};
        nextMove[5]= vector<int>{};
        nextMove[6]= vector<int>{0,1,7};
        nextMove[7]= vector<int>{2,6};
        nextMove[8]= vector<int>{1,3};
        nextMove[9]= vector<int>{4,2};
        
        int total =0;
        for(int i=0; i<=9; i++){
            total=  (total + dfs(n-1, i ))% mod;
        }
        return total;
    }
    
    int dfs(int moves_left, int curr_cell){
        if( moves_left==0)
            return 1;
        
        if( dp[moves_left][curr_cell] != -1)
            return dp[moves_left][curr_cell];
        
        int total =0;
        for(auto next: nextMove[curr_cell]){
            total= (total + dfs(moves_left-1, next))%mod;
        }
        
        return dp[moves_left][curr_cell] = total%mod;
    }
};