class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        
        vector<int> color(n);
        
        for(int node=0; node<n; node++){
            
            // if ith node isnt colored yet, it isnt visited yet
            if( color[node])
                continue;
            color[node]=1;
            
            queue<int> q;
            q.push(node);
            
            while(!q.empty()){
                int sz = q.size();
                
                for(int i=0;i <sz; i++ ){
                    int topnode= q.front(); // 0
                    q.pop();
                    
                    
                    for(auto& adj: graph[topnode]){
                        if( color[adj] == color[topnode])
                            return false;
                        
                        if( color[adj] )
                            continue;
                        color[adj]= -color[topnode];
                        q.push(adj);
                        
                    }
                }
            }
        }
        
        return true;
    }
};