class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        // n=0, return 1;
        // n=1, return 9 + dp[0]          =   9 + 1   = 10
        // n=2; return 9*9  +dp[1]        =  81 + 10  = 91
        // n=3, return 9*9*8 + dp[2]      = 648 + 91  = 739
        // n=4, return 9*9*8*7 + dp[3]    = 4536+ 739 = 5275
        //............
         
        vector<int> dp(n+1);
        dp[0]=1;
        
        int base =9, factor=9;
        for(int i=1; i<=n; i++){
            
            if( i>1)
                base*= (factor--); // 9*9 = 81 *8
            
            dp[i]= base + dp[i-1];
        }
        
        return dp[n];
    }
};