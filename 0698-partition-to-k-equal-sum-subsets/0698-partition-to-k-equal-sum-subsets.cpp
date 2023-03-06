class Solution {
    bool visited[16]={0};
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n= nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        sort(nums.begin(), nums.end(), greater<int>());
        return ( (sum%k ==0) and dfs( nums, k, 0, 0, sum/k ));
    }

    bool dfs(vector<int>& nums, int k, int idx, int sum, int  target){
        if( k==1)
            return 1;

        if( sum> target or idx>= nums.size())
            return 0;
        if( sum== target)
            return dfs(nums, k-1, 0, 0, target);

        for(int i= idx; i<nums.size(); i++){
            if( !visited[i]){
                visited[i]=1;

                if ( dfs( nums, k, i+1, sum+nums[i], target))
                    return true;

                visited[i]=0;
            }
        }

        return false;

    }
};