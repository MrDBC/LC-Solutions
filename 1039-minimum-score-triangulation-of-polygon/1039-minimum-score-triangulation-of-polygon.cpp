class Solution {
    int dp[50][50];
public:
    int minScoreTriangulation(vector<int>& values) {
        int n= values.size();
        memset(dp, -1, sizeof(dp));
        return  domcm(values, 0, n-1);
    }
    int domcm(vector<int>& values, int i, int j){
        
        // atleast 3 vertices needed to make a polygon( triangle)
        if( (j-i) < 2)
            return 0;
        
        if( dp[i][j] != -1)
            return dp[i][j];
        
        int minscore = INT_MAX;
        // fix any 2 consecutive vertices and 
        // recurse for the sub-polygons
        
        for(int k=i+1; k<j; k++){
            
            minscore = min( minscore, (values[i]* values[k] * values[j] ) +
                domcm(values, i,k) + domcm(values, k,j) );
        }
        
        return dp[i][j] = minscore;
    }
};