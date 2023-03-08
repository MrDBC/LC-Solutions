class Solution {
public:
    long int findHoursTaken(vector<int>& piles, int speed){
        long int hrs =0;
        for(auto cnt: piles)
            hrs+= (long)(cnt+ (speed-1))/speed;
        
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        
        int lowspeed=1 , highspeed=* max_element(begin(piles), end(piles)) ;
        int ans=-1;
        while( lowspeed <= highspeed){
            int midspeed = lowspeed + (highspeed - lowspeed)/2;
            
            long hrs_taken = findHoursTaken(piles, midspeed);
            
            if( hrs_taken <= h){
                ans = midspeed;
                highspeed = midspeed - 1;
            }
            
            else
                lowspeed = midspeed +1;
        }
        
        return ans;
    }
};