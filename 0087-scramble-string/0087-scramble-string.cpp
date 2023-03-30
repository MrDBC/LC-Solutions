class Solution {
    unordered_map<string, bool> dp;
public:
    bool isScramble(string s1, string s2){
        return mcm(s1, s2);
    }
    
    bool mcm( string s1, string s2){
        // if both strings are same, return true
        // no need to check anything
        if(s1 == s2)
            return true;
        
        int n = s1.size();
        string key= s1+" "+s2;
        if( dp.count(key))
            return dp[key];
        
        // let s1=a+b, s2 = c+d
        // we recursively check for both conditions:
        // dont scramble s2 : check(a,c) and check(b,d) for equality
        // scramble s2 :  check(a,c) and check(d,b) for equality
        
        
        
        // we are going till len ==n-1 because, we need both left &
        // right substrings to be not null
        for(int len=1; len<n; len++){
            string a= s1.substr(0,len), b= s1.substr(len);
            string c= s2.substr(0,len), d= s2.substr(len);
            
            if( mcm(a,c) && mcm(b,d))
                return dp[key]= true;
            
            string c_scrambled = s2.substr(n-len), d_scrambled= s2.substr(0, n-len);
            if( mcm(a, c_scrambled) and mcm(b, d_scrambled))
                return dp[key]= true;
        }
        
        return dp[key]= false;
    }
};