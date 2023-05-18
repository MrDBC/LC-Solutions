class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // vector<vector<int>> g(n);
        
        
        set<int> us;
        vector<int> res;
        for(int i=0; i< n; i++){
            // g[edges[i][0]].push_back(edges[i][1]);
            us.insert(i);
        }
        
        
        for(int i=0; i<edges.size(); i++)
            us.erase(edges[i][1]);
        
        for(auto node: us)
            res.emplace_back(node);
        
        return res;
        
        
    }
};