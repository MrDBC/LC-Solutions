class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int lowdivisor=1, highdivisor=1e6;
        
        while(lowdivisor < highdivisor){
            int middivisor = (lowdivisor + highdivisor)/2;
            
            int sum=0;
            for(auto x: nums)
                sum+= (x+middivisor-1) / middivisor;
            
            if(sum <= threshold)
                highdivisor = middivisor;
            else
                lowdivisor = middivisor +1;
        }
        
        return lowdivisor;
    }
};