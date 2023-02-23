class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n= profits.size();
        vector<vector<int>> cap_pro;
        // we need to pick projects within our ccurrent capital(w) range
        // so make {capital[i], profits[i]} pair and sort them in ascending order
        
        for(int i=0; i<n; i++)
            cap_pro.emplace_back(vector<int>{capital[i], profits[i]});
        
        sort(cap_pro.begin(), cap_pro.end()); // TC: O(n logn)
        
        // now we gonna run a loop k times( at most), to choose our best possible
        // k(at most) projects to maximise our profits
        priority_queue<int> max_profit;
        
        int i=0, curr_capital=w;
       
        while(k--){  // TC:O(k)
            
            // while more projects exists, and capital needed for these projects
            // is less than equal to the  "curr_capital" we have currently,
            // push the corresponding profits of those projects into our maxheap
           
            while(i<n and cap_pro[i][0]<= curr_capital )  // TC: O(n log n) not every k times, but overall ( please note)   
                max_profit.push(cap_pro[i++][1]);
        
            
            // if max_profit( priority queue) is empty, it means either of 2 things:
            // 1. we have exhausted processing all our projects
            // 2. the projects left, have capital needs > our current capital
            // so just break 
            if( !max_profit.size())    // TC: O(1) 
                break;
            
            // else, pick the project within capital range( this is taken care by the while loop condition above)
            // and which gives maximum profit( this is taken care of by our max-heap "max_profit")       
            else{     // TC: O(1) for retrieval of top value & O(log n) for popping = overall O(log n)
                curr_capital+= max_profit.top();
                max_profit.pop();
            }
        }
        // overall TC for the while loop:
        // O(k) for the while loop iteration
        // O(n*logn) we push maximum n elements in our maxheap('max_profit')and  pop max n times too
        // so overall TC: O(max(k, nlog n))
        
        // overall for the whole algorithm:
        // O(n logn) for sorting + O(max(k, nlog n)) for the while looop operations
        // so overall TC: O(max(k, nlog n))
        
        return curr_capital;
    }
};