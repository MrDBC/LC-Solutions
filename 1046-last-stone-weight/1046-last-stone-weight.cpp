class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n= stones.size();
        
        priority_queue<int> pq;
        for( int i=0;i <n; i++)
            pq.push(stones[i]);
        
        while( pq.size()>1){
            int top= pq.top();
            pq.pop();
            int sec= pq.top();
            pq.pop();
            if( top==sec)
                continue;
            else
                pq.push(top-sec);
        }
        
        if( pq.size()==1)
            return pq.top();
        else
            return 0;
    }
};