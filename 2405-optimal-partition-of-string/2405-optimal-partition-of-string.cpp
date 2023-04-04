class Solution {
public:
    int partitionString(string s) {
        
        unordered_set<char>  us;

        int  r=0,partition=0, n= s.size();
        while( r<n){
            if( us.find(s[r]) != us.end()){ // if this char is duplicate,partition & reset the set
                ++partition; // 1 2
                us.clear();
            }
            us.insert(s[r]);
            
            ++r;
        }

        return partition+1;
    }
};