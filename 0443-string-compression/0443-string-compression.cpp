class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        
        int count=0, idx=0; 
        char ch = chars[0];
        // a 
        for(int i=0; i<n ;i++){
            if( i==0 or ch!= chars[i]){
                
                string cnt = to_string(count);
                int k=0;
                while(count>1 and k<cnt.size()){
                    chars[idx++]= cnt[k++];
                }
                
                chars[idx++]= chars[i];
                ch= chars[i]; // a
                count=1; 
            }else{
                ++count;
            }
        }
        
        string cnt = to_string(count);
        int k=0;
        while(count>1 and k<cnt.size()){
            chars[idx++]= cnt[k++];
        }

        
        
        return idx;
    }
};