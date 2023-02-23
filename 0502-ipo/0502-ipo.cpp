class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n= profits.size();
        vector<vector<int>> cap_pro;
        // we need to pick projects within our ccurrent capital=w, range
        // so make {capital[i], profits[i]} pair and sort them
        
        for(int i=0; i<n; i++)
            cap_pro.emplace_back(vector<int>{capital[i], profits[i]});
        
        sort(cap_pro.begin(), cap_pro.end());
        
        // now we gonna run a loop k times( at most), to choose our best possible
        // k(at most) projects to maximise our profits
        priority_queue<int> max_profit;
        
        int i=0, curr_capital=w;
        while(k--){
            
            // while more projects exists, and capital needed for these projects
            // is less than equal to the  capital('w') we have currently
            while(i<n and cap_pro[i][0]<= curr_capital )
                // push the corresponding profits of those projects into our maxheap
                max_profit.push(cap_pro[i++][1]);
        
            
            // if max_profit( priority queue) is empty, it means either of 2 things:
            // 1. we have exhausted all our projects
            // 2. the projects left, have capital needs > our current capital
            // so just break 
            if( !max_profit.size())
                break;
            
            // else, pick the project within capital range( this is taken care by the while loop condition)
            // and which gives maximum profit( this is taken care of by our max-heap)
            else{
                curr_capital+= max_profit.top();
                max_profit.pop();
            }
        }
        
        return curr_capital;
    }
};