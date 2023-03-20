class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n= flowerbed.size();
        
        for(int i=0;i <n ; i++){
            if(flowerbed[i]==1 or ((i-1)>=0 and flowerbed[i-1]!=0) or ((i+1)<n and flowerbed[i+1]!=0))
                continue;
            
            flowerbed[i]=1; // plant flower here and mark it
            --k;
        }
        return k<=0;
    }
};