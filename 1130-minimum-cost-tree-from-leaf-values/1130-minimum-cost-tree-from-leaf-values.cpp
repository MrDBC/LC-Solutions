class Solution {
    int dp[40][40];
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n= arr.size();
        memset(dp, -1, sizeof(dp));
        return dfs( arr, 0, n-1);
    }
    int dfs( vector<int>& arr, int i, int j){
        // if we have only 1 node in a subtree
        // it cant be multiplication partner , so 
        // return 0 ( becoz it has been used for
        // multiplication either as leftmax or rightmax)
        if( i==j)
            return 0;
        
        if( dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;
        // [6,2,4]
        for(int k=i; k<j; k++){
            // left subtree (i...k) rightsubtree ( k+1..j)
            int leftmax =INT_MIN, rightmax= INT_MIN;
            
            // find the max node val in left & right subtree
            for(int a=i; a<=k; a++)
                leftmax = max(leftmax, arr[a]);
            for(int a=k+1; a<=j; a++)
                rightmax = max(rightmax, arr[a]);
            
            // then, mulitply leftmax & rightmax node values in left 
            // & right subtrees, after that recursively call the 
            // left & right subtrees which returns the minimum combination
            mini = min(mini, leftmax*rightmax + dfs(arr, i,k)+dfs(arr, k+1,j ));
        }
        
        return dp[i][j] = mini;
    }
};