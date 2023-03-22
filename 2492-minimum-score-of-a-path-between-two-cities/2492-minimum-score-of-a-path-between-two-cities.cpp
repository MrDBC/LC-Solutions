class Solution {
    int minscore = INT_MAX;
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<pair<int, int>> g[n+1];
        for(auto x: roads){
            int u = x[0] , v = x[1], dist = x[2];
            g[u].push_back(make_pair(v, dist));
            g[v].push_back(make_pair(u, dist));
        }
        
        vector<int> visited(n+1, 0);
        
        dfs( g, 1, visited);
        return minscore;
    }
    void dfs(vector<pair<int, int>> g[], int city,vector<int> &visited){
        
        if( visited[city] ==1)
            return;
        
        visited[city]= 1;
        for(auto x: g[city]){
            int v= x.first , dist=x.second;
            
            minscore= min( minscore, dist);
            dfs( g, v, visited);
        }
    }
};