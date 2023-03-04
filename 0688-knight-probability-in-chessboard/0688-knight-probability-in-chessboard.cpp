class Solution {
    vector<int> dirs{2 ,1, -2, -1, 2, -1, -2, 1, 2};
    // double dp[25][25][101];
public:
    // no TLE: bottom-down 
    // TC & SC: O( n^2 * k)
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<vector<double>>> dp(n, vector<vector<double>> (n, vector<double>(k+1, 0)));
        // we are initially standing at chess[row][column] and so even if we have 0 moves left,
        // we having probability =1, beoz we are already standing there
        
        dp[row][column][0] = 1;  
        
        
        for(int i=0; i<k; i++){
            for(int r=0; r<n; r++){
                for(int c=0; c<n; c++){

                    for(int d=0; d<8; d++){
                        int next_row = r+ dirs[d];
                        int next_col = c+ dirs[d+1];

                        // becoz the next move is so random, and non linear,
                        // instead of moving from chess[r][c] to chess[next_r][next_c]
                        // we assume, we want to jump from chess[next_r][next_c] to chess[r][c]
                        // this way we would have pre-computed our values, so it gets our job done
                        if( min(next_row, next_col)>=0 and max(next_row, next_col)<n)
                            dp[next_row][next_col][i+1] += ((double)1/8) *dp[r][c][i] ;
                    }
                }
            }
        }
        
        double ans = 0;
        
        // for given k moves, we calculate the probabilities of each cell
        // of the chess, in our answer and return it
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += dp[i][j][k];
            }
        }
        return ans;

    }
};