class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n= edges.size();
        int maxcycle = -1;
        vector<int> visitedAtTime(n,0);
        
        int time=1;
        for(int i=0; i<n; i++){
            if( visitedAtTime[i] != 0)
                continue;
            
            int startTime = time;
            int node = i;
            while( node!= -1 and visitedAtTime[node] ==0){
                visitedAtTime[node] = time++;
                node = edges[node];
            }
            
            if(node!= -1 and visitedAtTime[node]>= startTime)
                maxcycle = max( maxcycle, time - visitedAtTime[node]);
        }
        
        return maxcycle;
    }
};