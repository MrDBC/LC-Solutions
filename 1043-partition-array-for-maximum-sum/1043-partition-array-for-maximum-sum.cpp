class Solution {
    int dp[501][501];
public:
    // no TLE: RECURSION + memo = top down
    int maxSumAfterPartitioning(vector<int>& arr, int sub_size) {
        int n= arr.size();
        
        memset(dp, -1, sizeof(dp));
        return dfs( arr, 0, n-1, sub_size);
    }
    int dfs( vector<int>& arr, int i, int j, int sub_size){
        if( i==j)
            return arr[i];
        
        if( dp[i][j] !=-1)
            return dp[i][j];
        
        
        int max_sum=0, max_val =0;
        for(int k=1; k<= min(sub_size, j-i+1); k++){
            
            // i, i+1, ..., i+(k-1)
            
            max_val= max(max_val , arr[i+k-1]); 
            
            max_sum = max(max_sum, (k* max_val) + dfs(arr, i+k, j, sub_size) );
        }
        
        return dp[i][j] = max_sum;
    }
};