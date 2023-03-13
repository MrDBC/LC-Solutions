class Solution {
    // dp[i] denotes max. value Alice can pick up from (i....n-1)
    int dp[50001] = {[0 ... 50000] = INT_MIN};
public:
    string stoneGameIII(vector<int>& arr) {
        int n= arr.size();
        
        int alice_net_val=dfs(arr, 0);
        
        return (alice_net_val==0)? "Tie": (alice_net_val > 0)? "Alice" : "Bob";
    }
    
    int dfs(vector<int>& arr, int i){
        int n= arr.size();
        
        if( i==n)
            return 0;
        
        if( dp[i] != INT_MIN)
            return dp[i];
        
        int take_val =0, max_val =INT_MIN;
        for(int k=i; k<= min(n-1, i+2); k++){
            take_val += arr[k];
            max_val = max(max_val, take_val - dfs(arr, k+1) );
        }
        
        return dp[i]= max_val;
    }
};