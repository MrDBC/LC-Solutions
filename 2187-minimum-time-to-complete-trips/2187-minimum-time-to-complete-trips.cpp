class Solution {
public:
    long   find( vector<int>& time, long mid){
        long takes =0;
        for( int i=0; i< time.size(); i++){
            takes += mid/ time[i];
        }
        return takes;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n= time.size();
        
        sort(time.begin(), time.end());
        
        long high = (long long)(*time.begin()) * totalTrips;
        
        long low =1, mid;
        
        while( low < high){
             mid =low+ (high - low)/2;
                
            long curr_takes= find(time, mid);
            cout<< curr_takes<<endl;
            if( curr_takes >= totalTrips )
                high= mid;
            else 
                low= mid+1;
            
        }
        return low;
    }
};