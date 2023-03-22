class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<pair<int, int>> g[n+1];
        for(auto x: roads){
            int u = x[0] , v = x[1], dist = x[2];
            g[u].push_back(make_pair(v, dist));
            g[v].push_back(make_pair(u, dist));
        }

        
        
        int minscore = INT_MAX;
        queue<int> q;
        q.push(1);
        
        vector<int> visited(n+1, 0);
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0; i<sz; i++){
                int u = q.front();
                visited[u]=1;
                q.pop();
                
                for(auto x: g[u]){
                    int v= x.first , dist=x.second;
                    if( visited[v] != 0)
                        continue;
                    
                    minscore= min( minscore, dist);
                    q.push(v);
                }
            }
        }
        
        return minscore;
    }
};