class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int n= intervals.size();
        
        vector<int> ans(n);
        map<int, int> m;
        
        /// mapping starting value of an interval to its index
        for(int i = 0; i < intervals.size(); i++)
            m[intervals[i][0]] = i;
        
        for(int i = 0; i < intervals.size(); i++) {
            auto itr = m.lower_bound(intervals[i][1]);
            ans[i]  = itr!=end(m)? itr-> second: -1;
        }
        return ans;
    }
};