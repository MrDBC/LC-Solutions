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
        // fix vertices i & j and select a 3 vertex lying in range (i, j)  
        // [non- including i & j ofc \U0001f602]
        // form a triangle using (i , k, j) and then 
        // recurse for the sub-polygons
        
        for(int k=i+1; k<j; k++){
            
            // score of forming triangle (i, k, j)
            int tri_score = (values[i]* values[k] * values[j] ) ;
            minscore = min( minscore, tri_score+ domcm(values, i,k) + domcm(values, k,j) );
        }
        
        return dp[i][j] = minscore;
    }
};