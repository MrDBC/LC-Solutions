class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        
        // for me: a window is a consecutive set of same characters
        int count=0, idx=0; 
        char prev_char = chars[0];
      
        for(int i=0; i<=n ;i++){
            
            // this is where we are pushing new character of a window
            // ( at the start of a window) and also their counts when 
            // we reach the start of the next window
            if( i==0 or i==n or  prev_char!= chars[i]){
                
                string cnt = to_string(count);
                int k=0;
                // adding the count only if it is > 1 ( 
                // we add previous character's count (in prev window)
                // when we encounter a new character in a new window)
                while(count>1 and k<cnt.size())
                    chars[idx++]= cnt[k++];
                
                // adding 1st character of a window
                // storing the ist character in a window u encounter
                // to compare it with the following characters in the
                // same window [see the if condition]
                if( i<n){
                    chars[idx++]= chars[i];
                    prev_char= chars[i]; 
                }
                
                // this is for the ist character in a window
                count=1; 
            }else{
                // while we are in the same window , increase the count
                ++count;
            }
        }
        
        
        return idx;
    }
};