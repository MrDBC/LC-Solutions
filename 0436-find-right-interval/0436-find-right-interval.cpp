class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<pair<int,int>> map;
        
        for(int i = 0; i < n; i++) 
            map.push_back({intervals[i][0],i});
        
        sort(map.begin(), map.end());
        
        vector<int> ans;
        for(auto v : intervals) {
        
            // custome lower_bound, signs are opposite
            // ig other than vector or pair
            auto it = lower_bound(map.begin(), map.end(), v[1], [](pair<int, int>& a, int b) { return a.first < b;});
         
            ans.push_back(it == map.end() ? -1 : it->second);
        }
        
        return ans;
    }
};