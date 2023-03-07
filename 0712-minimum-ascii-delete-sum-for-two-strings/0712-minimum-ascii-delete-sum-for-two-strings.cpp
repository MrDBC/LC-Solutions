class Solution {
    vector<vector<int>> dp;
public:
    int minimumDeleteSum(string s1, string s2) {
        int m= s1.size(), n= s2.size();
        
        dp.resize(m+1,vector<int>(n+1,-1));
        
        return deleteNonLcs(s1,s2, m, n);
    }
    
    int deleteNonLcs(string& s1, string& s2, int m, int n){
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        if( !m and !n )
            return 0;
        if(!m)
            return accumulate(s2.begin(), s2.begin()+n, 0);
        if( !n)
            return accumulate(s1.begin(), s1.begin()+m, 0);
        
        int ans = 0;
        if( s1[m-1] == s2[n-1])
            ans = 0 + deleteNonLcs(s1,s2,m-1,n-1);
        else
            ans = min( int(s1[m-1]) + deleteNonLcs(s1,s2,m-1,n) , int(s2[n-1]) + deleteNonLcs(s1,s2,m,n-1));
        
        return dp[m][n] = ans;
    }
};
