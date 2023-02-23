class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int minWeight = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            int sum = 0;
            int d = days;
            bool flag = false;
            for(auto &weight:weights){
                sum +=weight;
                if(sum>mid){
                    if(d>0){
                        sum = weight;
                        d--;
                    }else{
                        flag = true;
                        break;
                    }
                }
            }
         if(d ==0){
            low = mid+1;
          }else{
            minWeight = min(minWeight,mid);
            high = mid-1;
          }
        }
    return minWeight;
    }
};