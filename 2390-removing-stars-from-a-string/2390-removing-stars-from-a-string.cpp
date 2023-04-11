class Solution {
public:
    string removeStars(string s) {
        int n= s.size();
        
        int netstars=0;
        string res="";
        
        int i=n-1;
        while(i>=0){
            if( s[i]=='*')
                ++netstars;
            else{
                if( netstars)
                    --netstars;
                else
                    res+= s[i];
            }
            
            i--;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};