class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n= nums.size();
        
        priority_queue<int> pq;
        int mini = INT_MAX; // current minimum element  after making alll even
        /// we are basically lessenng one operation by making all odd no.s even( *2)
        // now we have all no.s as even, so we will just focus on "dividing by 2" operation
        
        for( int i=0; i<n; i++){
            int ele = (( nums[i]%2)? nums[i] * 2 : nums[i]);
            mini = min( mini, ele );
            pq.push(ele);
        }
                
    
        int min_dev = INT_MAX;
        while( (pq.top())%2 ==0){
            min_dev= min( min_dev, (pq.top() - mini));
            mini = min( mini, (pq.top())/2);
            pq.push( pq.top()/2);
            pq.pop();
        }
        
        return min( min_dev, pq.top() - mini);
    
    }
};