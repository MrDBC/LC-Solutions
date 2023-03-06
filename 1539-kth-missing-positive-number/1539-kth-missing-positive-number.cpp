class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> us(begin(arr), end(arr));
        
        int cnt=0;
        for(int i=1; i<=1000; i++){
            if( us.count(i) )
                continue;
            else
                ++cnt;
            
            if( cnt==k)
                return i;
        }
        
        return 1000+ (k-cnt);
    }
};