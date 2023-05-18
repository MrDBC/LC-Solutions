class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // vector<vector<int>> g(n);
        
        
        unordered_set<int> us;
        vector<int> res;
        for(int i=0; i<edges.size(); i++){
            // g[edges[i][0]].push_back(edges[i][1]);
            us.insert(edges[i][1]);
        }
        
        
        for(int i=0; i<n; i++)
            if ( us.find(i) == us.end())
                res.emplace_back(i);
        
        
        return res;
        
        
    }
};