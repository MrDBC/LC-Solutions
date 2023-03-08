class Solution {
    // int dp[50][50];
public:
    int minScoreTriangulation(vector<int>& values) {
        int n= values.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
  
        // fix vertices i & j and select a 3 vertex lying in range (i, j)  
        // [non- including i & j ofc \U0001f602]
        // form a triangle using (i , k, j) and then 
        // recurse for the sub-polygons
        
        for(int i=n-3; i>=0; i--){
            for( int j= i+2; j<n; j++){
                
                dp[i][j] = INT_MAX;
                for(int k=i+1; k<j; k++){
                    
                    int tri_score = (values[i]* values[k] * values[j] ) ;
                    dp[i][j]= min( dp[i][j] , tri_score+ dp[i][k] + dp[k][j] );
                }
            }
        }

            
        return dp[0][n-1];
    }
};