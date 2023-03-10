class Solution {
    int mod = 1e9+7;
    // int dirs[]= {-1,-1,0, -1};
    vector<vector<vector<int>>> dp;
public:
     vector<int> pathsWithMaxScore(vector<string>& board) {
        int m= board.size(), n= board[0].size();
     
        dp.resize(m+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        
        vector<int> res = dfs( board, 0,0); 
        
        if( dp[m-1][n-1][0] != -1)
            return res;
        else
            return vector<int> {0,0};
    }
    
    vector<int> dfs( vector<string>& board, int i, int j){
        int m= board.size(), n= board[0].size();
        
        if( i>=m or j>=n or board[i][j] == 'X')
            return vector<int>{0,0};
        
        if( dp[i][j][0] != -1 )
            return dp[i][j];
        if( i==m-1 and j==n-1){
            // we reached our target (bottom right square, so return 
            // path sum=0, and no of paths= 1)
            
            return dp[m-1][n-1] = {0,1};
        }
        vector<int> right = dfs( board, i, j+1);
        vector<int> down = dfs(board, i+1, j);
        vector<int> down_right = dfs( board, i+1, j+1);
        
        vector<int> max_path(2);
        max_path[0]= max( right[0], max(down[0], down_right[0]));
     
        if( max_path[0] == right[0])
            max_path[1]= (max_path[1]+right[1])%mod;
            
        if( max_path[0] == down[0])
            max_path[1]= (max_path[1]+down[1])%mod;
        
        if( max_path[0] == down_right[0])
            max_path[1]= (max_path[1]+down_right[1])%mod;
        
        max_path[0] += (board[i][j] == 'E')? 0: board[i][j]-'0' ;
        return dp[i][j]= max_path;
    }
   
};