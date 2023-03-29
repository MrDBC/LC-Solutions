class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if( n==1)
            return vector<int>{0};
        
        vector<unordered_set<int>> g(n);
        
        for(auto x: edges){
            int u = x[0], v= x[1];
            g[u].insert(v);
            g[v].insert(u);
        }
        
        vector<int> leaflist;
        for(int i=0; i<n; i++)
            if( g[i].size() == 1)
                leaflist.emplace_back(i);
        
        
        while(n > 2){
            n-= leaflist.size();
            vector<int> newleaflist;
            
            for(auto leaf: leaflist){ // 0 1 2 5
                for(auto adj: g[leaf]){
                    g[adj].erase(leaf);
                    
                    if( g[adj].size() == 1)
                        newleaflist.emplace_back(adj);
                }
            }
            
            leaflist = newleaflist;
        }
        return leaflist;
        
    }
};