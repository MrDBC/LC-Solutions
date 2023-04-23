class Solution {
    int dp[100001];
    int mod=1e9+7;
public:
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof(dp));
        
        return dfs( s, 0, s.size(), k);
    }
    int dfs(string& s, int idx , int n, int k){
        if( idx==n)
            return 1;
        if( s[idx] == '0' )
            return 0;
        
        if( dp[idx] != -1)
            return dp[idx];
        
        string temp="";
        int cnt =0;
        for(int i=idx; i<n; i++){
            temp+= s[i];
            
            
            if( stol(temp)<= k )
                // cout<<temp<<endl;
                cnt = (cnt + dfs(s, i+1, n, k))%mod;
            else
                break;
        }
        
        return dp[idx] = cnt;
    }
};