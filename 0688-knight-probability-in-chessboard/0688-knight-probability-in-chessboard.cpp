class Solution {
    vector<int> dirs{2 ,1, -2, -1, 2, -1, -2, 1, 2};
    unordered_map<string, double> dp;
public:
    // no TLE: top-down 
    // TC & SC: O( n^2 * k)
    double knightProbability(int n, int k, int row, int column) {
        
        return dfs(n, k, row, column);
    }
    
    double dfs(int n, int k, int r, int c){
        // out of bounds check
        if(k==0)
            return 1;

        string key = to_string(r)+" "+to_string(c)+" "+to_string(k);
        if( dp.count(key) != 0)
            return dp[key];
        
        double prob=0;
        for(int i=0; i<8; i++){
            int next_row = r+ dirs[i];
            int next_col = c+ dirs[i+1];

            if( min(next_row, next_col)<0 or max(next_row, next_col)>=n)
                continue;
            prob+= ((double)1/8) * dfs(n, k-1, next_row, next_col);
        }
        
        return dp[key]= prob;
        
    }
};