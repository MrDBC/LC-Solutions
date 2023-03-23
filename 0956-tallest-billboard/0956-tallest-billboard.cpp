#define MAX 5000
class Solution {
public:
    int dp[21][2*MAX];
    int tall(int idx,int leftsum,int rightsum,vector<int>& rods)
    {   
      //  string temp=to_string()

        if(idx==rods.size()){
            if(leftsum==rightsum)return 0; //if both subset have equal sum
            return INT_MIN;
        }
        if(dp[idx][leftsum-rightsum+MAX]!=-1)return dp[idx][leftsum-rightsum+MAX];

        int best=INT_MIN;

        best = tall(idx+1,leftsum,rightsum,rods);//do not pick
        best = max(best,tall(idx+1,leftsum+rods[idx],rightsum,rods)+rods[idx]); //in the lest subset
        best = max(best,tall(idx+1,leftsum,rightsum+rods[idx],rods));//pick in the right subset


        dp[idx][leftsum-rightsum+MAX]=best;
        return dp[idx][leftsum-rightsum+MAX];

    }
    int tallestBillboard(vector<int>& rods) {

        memset(dp,-1,sizeof(dp));

        return tall(0,0,0,rods);
        
    }
};