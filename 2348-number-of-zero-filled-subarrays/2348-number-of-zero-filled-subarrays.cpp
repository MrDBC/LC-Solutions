class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        
        map<int, int> contiguous;
        int i=0, j=0;
        while( j<n){
            int encountered0= false;
            while( i<=j and j<n and nums[j]==0){
                ++j;
                encountered0= true;
            }
            
            contiguous[(j-i)]++;
            
            if( encountered0 == false){
                ++i, ++j;
            }
            else
                i=j;
        }
        
        long long ans=0;
        for(auto it: contiguous){
            long long  sub_size = it.first, freq= it.second;
            
            ans += (freq * (sub_size * (sub_size+1)/2));
        }
                    
        return ans;
    }
};