class Solution {
public:
    bool checkRecord(string s) {
        
        int n= s.size();
        int count_absent=0;
        int count_consecutive_lates =0;
        
        int i=0;
        while( i<n){
            count_absent+= (s[i]=='A')?1: 0;
            
            if( count_absent > 1)
                return false;
            
            count_consecutive_lates =0;
            while(i<n and  s[i]=='L')
                ++i,++count_consecutive_lates;
            
            // cout<<count_consecutive_lates<<endl;
            if (count_consecutive_lates !=0)
                --i;
            if( count_consecutive_lates > 2)
                return false;
            
            ++i;
        }
        
        return true;
    }
};