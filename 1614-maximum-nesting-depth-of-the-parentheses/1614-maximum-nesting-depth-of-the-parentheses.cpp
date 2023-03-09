class Solution {
public:
    int maxDepth(string s) {
        
        int max_depth_so_far=0, net_openings =0;
        
        for(int i=0; i<s.size(); i++){
            if( s[i] == '(')
                ++net_openings;
            else if( s[i] ==  ')')
                --net_openings;
            
            max_depth_so_far = max( max_depth_so_far, net_openings);
        }
        
        return max_depth_so_far;
        
    }
};