class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int low=1;
        int high=Integer.MIN_VALUE;
        for(int i=0;i<piles.length;i++){
            high=Math.max(high,piles[i]);
        }
        
        int ans= -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(blackbox(mid,piles,h)){
                ans = mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return low;
    }
    public boolean blackbox(int maxpiles,int[] piles,int h){
        long hours=0;
        for(int i:piles){
            int time=i/maxpiles;
            hours+=time;
            if(i%maxpiles!=0) hours++;
        }
        if(hours<=h)
            return true;
        return false;
    }
}