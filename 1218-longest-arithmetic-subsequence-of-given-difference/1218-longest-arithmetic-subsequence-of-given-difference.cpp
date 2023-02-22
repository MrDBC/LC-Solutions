class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n= arr.size();
        
        unordered_map<int,int> dp;

        int maxlen=1;
        for(int curr_value: arr){
            int prev_value = curr_value - difference;
            if( dp[prev_value] ==0)
                dp[curr_value] =1;
            else
                dp[curr_value]= 1+ dp[prev_value];

            maxlen= max(maxlen, dp[curr_value]);
        }

        return maxlen;
    }
};