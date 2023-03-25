class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto x: edges){
            int u= x[0], v=x[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        vector<int> visited(n,0);
      
        vector<long long > res;
        for(int i=0;i <n; i++){
            if( visited[i])
                continue;
            visited[i]=1;
            res.push_back(dfs(i,visited, g));
        }
        
        long long cnt=0;
        // res    - 4 2 1
        // prefix -   4 6 7
        //        (2*4) + (1*6) = 14
        
        vector<long long > pre(res.size());
        pre[0]= res[0];
        for(int i=1; i<res.size(); i++){
            pre[i] = pre[i-1] + res[i];
        }
        for(int i=0; i <pre.size()-1; i++){
           cnt+= pre[i]* res[i+1];
        }
        
        return cnt;
    }
    int dfs( int node,  vector<int>& visited, vector<vector<int>>& g){
        int cnt=1;
        for(auto adjnode: g[node]){
            if( !visited[adjnode]){
                visited[adjnode]=1;
                cnt+= dfs(adjnode, visited, g);
            }
        }
        return cnt;
    }
};