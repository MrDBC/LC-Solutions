
class Solution {
public:
    int dp[21][5000+1];
    int dfs(int idx,int leftsum, int rightsum,vector<int>& rods)
    {
        if(idx == rods.size()){
            if(leftsum==rightsum)
                return 0; //if both subset have equal sum
            return -50001;
        }
        
        int diff = abs(leftsum-rightsum);
        
        if(dp[idx][diff] != -1)
            return dp[idx][diff];

        int donttake = dfs(idx+1, leftsum, rightsum, rods);
        int addtoleft = rods[idx] + dfs(idx+1, leftsum + rods[idx], rightsum, rods);
        int addtoright = rods[idx] + dfs(idx+1, leftsum , rightsum + rods[idx], rods);
        
        
        return dp[idx][diff] = max(donttake, max(addtoleft, addtoright));
    }
    int tallestBillboard(vector<int>& rods) {

        memset(dp,-1,sizeof(dp));

        return dfs(0,0,0,rods)/2;
        
    }
};