class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        
        if( n< (long)m*k)
            return -1;
        
        int low = 1, high = 1e9;
        while( low < high){
            int mid = (low+high)/2;
            
            int cnt=0, continuous=0;
            for(int i=0; i<=n; i++){
                if( i==n || bloomDay[i]> mid){
                    cnt+= (continuous/k);
                    continuous=0;
                }else{
                    continuous++;
                }
            }
            
            if(cnt < m)
                low= mid+1;
            else
                high = mid;

        }

        return low;
    }
};