class Solution {
    int cnt=0;
    vector<int> visited;
    set<pair<int,int>> s;
public:
    void dfs( vector<vector<int>>& g, int curr_city){
        if( visited[curr_city])
            return;

        visited[curr_city]=1; 
        
        for(auto adj_city : g[curr_city]){
            // to reach city 0 from all other cities, since we are doing dfs 
            // starting from city(0), all the road directions should be from
            // ( adj_city -> curr_city), if it isnt, do a cnt++ ( becoz ,we need
            // to change the road direction)
            
            if( visited[adj_city]==0 and s.find(make_pair(adj_city, curr_city)) == s.end() )
                ++cnt;
            
            dfs(g, adj_city);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        visited.resize(n, 0);
        
        
        for(auto x: connections){
            int u= x[0], v=x[1];
            s.insert(make_pair(u,v));
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs( g, 0);
        return cnt;
    }
};