class Solution {
    int i=0;
public:
    string decodeString(string s) {
        int n= s.size();
        string result="";
        while( i<n){
            
            // if we get a digit
            if( isdigit(s[i])){
                // form the number
                int times=0;
                while(isdigit(s[i]))
                    times= times*10 + s[i++]-'0';
                
                //number always succeeds a '['
                ++i;
                
                string dfs_decoded = decodeString(s);
                while(times--)
                    result+= dfs_decoded;
                
            }
            else if( s[i]== ']')
                return result;
            
            else if( isalpha(s[i]))
                result+= s[i];
            
            ++i;
        }
        return result;
    }
};