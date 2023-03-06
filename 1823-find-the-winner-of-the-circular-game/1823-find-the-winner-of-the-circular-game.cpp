class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int > q;
        for(int i=1; i<=n; i++)
            q.push(i);
        
        
        while(q.size()>1){
            int curr_k=k;
            
            while( curr_k-- > 1){
                int top= q.front();
                q.pop();
                q.push(top);
            }
            
            q.pop();
        }
        
        return q.front();
    }
};