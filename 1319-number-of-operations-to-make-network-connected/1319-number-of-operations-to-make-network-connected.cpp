class Solution {
public:
    void dfs(int node, vector<int> g[], vector<int>& visited){
        for(auto x: g[node]){
            if( !visited[x]){
                visited[x]=1;
                dfs(x, g, visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> g[n];
        
        for(auto x: connections){
            int u=x[0], v=x[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        queue<int> q;
        vector<int> visited(n,0);
        int disconnected_grps=0;

        for(int i=0; i<n; i++){
            if( visited[i])
                continue;
         
            dfs(i, g, visited);
            ++disconnected_grps;
        }
     
        return (connections.size() >= (n-1))? (disconnected_grps-1): -1;
    }
};