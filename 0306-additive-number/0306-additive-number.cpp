class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n= num.size();
    
        for(int alen=1; alen< (n+1)/2; alen++)
            for(int blen=1; blen < (n+1)/2; blen++)
               if( dfs( num.substr(0,alen) , num.substr(alen, blen), num.substr(alen+blen)))
                   return true;
            
        return false;
    }
    
    // 'a' and 'b' are fixed numbers
    // but 'containsC' is everything what 
    // is left after choosing our 'a' and 'b'
    int dfs(string a, string b, string containsC){
        if( a.size()>1 and a[0]=='0' or b.size()>1 and b[0]=='0')
            return false;
        
        // get the sum of 'a' & 'b'
        string c= to_string(stoll(a) + stoll(b));
        
        // if sum and our probable c (i.e, containsC) are equal
        // we have utilised the whole string 'num', so return true
        if( c==containsC)
            return true;
        
        // if the sum of 'a' + 'b' comes out to be greater than what is 
        // left in string 'num', thats invalid
        // also if the ist 'c.size()' digits of 'containsC' doesnt match up  with c
        // return false
        if( c.size()> containsC.size() || containsC.substr(0,c.size()) != c)
            return false;
        
        return dfs(b, c, containsC.substr(c.size()));
    }
};