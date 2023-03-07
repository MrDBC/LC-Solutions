class Solution {
public:
    long long findTotalTripsCovered(vector<int>& time, long long int timeEachBusGets){
        
        long long totalTripsCovered =0;
        for(auto t: time)
            totalTripsCovered+= (long long)timeEachBusGets / t;
            
        return totalTripsCovered;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n= time.size();
        
        long long time_start = 1, time_end= 10e13;// (long long)(*min_element(begin(time), end(time))) * totalTrips; 
        while( time_start < time_end){
            long long mid_time = time_start + (time_end - time_start )/2;
            
            // cout<<time_start<<" "<<mid_time<<" "<<time_end<<endl;
            // check the total trips all the buses can travel in mid_time units/hrs
            long long trips_covered = findTotalTripsCovered(time, mid_time);
            
            if(trips_covered >= totalTrips ){
                
                time_end = mid_time;
            }
            else
                time_start= mid_time+1;
            
        }
        
        return time_end;
    }
};