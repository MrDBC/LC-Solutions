class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        
        vector<vector<int> > dp(n + 1, vector<int>(k , INT_MAX));

        int prefix[n+1];
        for(int i=0; i<n; i++)
            prefix[i+1]= prefix[i]+ nums[i];
 
        // dp[i][j] denotes partition nums[i...n-1] by making j partitions in between

        // if k==0,( ie, no partitions possible), we need to find the sum of 
        // remaining subarray nums[i...n-1], 
        // which can be precalculated by using prefix array
        for(int i=0; i<n; i++)
            dp[i][0]= prefix[n]- prefix[i];

        // invalid subarray : if( i==n)   return INT_MAX;
        // ik we have already pre-initialized the dp , but im doing it just for practice
        // and transforming each line of recursive to bottomup
        for(int j=0; j<k; j++)
            dp[n][j] = INT_MAX;

        // i -> possible valid indices
        // j -> possible no of partitions (k subarrays means (k-1) partitions , also we have precalculated dp for partitions=0)
        for(int i=n-1; i>=0; i--){
            for(int j=k-1; j>0; j--){
                for(int mid=i; mid<n; mid++){

                    int sum= prefix[mid+1]- prefix[i]; 
                    // int partition = solve(nums, mid+1, k-1, prefix);
                    
                    dp[i][j] =  min(dp[i][j], max(sum, dp[mid+1][j-1]));
                }
            }
        }
        
        // partition nums[0....(n-1)] by making (k-1) partitions, such that the maximum 
        // possible subarray sum  is minimum
        return dp[0][k-1];
    }
 };