class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n= arr.size();
        
        int l=0, r=n-1;
        //  [2,3,4,7,11]
        //   0 1 2 3  4
        //   1 1 1 3  6
        
        // 1 2 3 4 5  k=10
        int idx =0;
        while( l<=r){
            int mid = (l+r)/2;
            
            int missing_till_mid_idx = arr[mid]-(mid+1);
            if( missing_till_mid_idx < k){
                l=mid+1;
            }
            else
                r=mid-1;   
        }
        
        return l+k; 
        
    }
};