 class Solution {
     public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1,m =0;
        for(int i=0;i<piles.size();i++){
            m = max(m,piles[i]);
        }
        while(l<=m){
            int mid = (l+m)/2;
            unsigned int tot = 0;
            cout<<mid<<" ";
            for(int i=0;i<piles.size();i++){
                
                tot+=(piles[i]/mid);
                
                if(piles[i]%mid)
                    tot++;
            }
            
            cout<<tot<<endl;
            if(tot>h){
                l = mid+1;
            }
            else
                m = mid-1;
        }
        return l;
    }

};