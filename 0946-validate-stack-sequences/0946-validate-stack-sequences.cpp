class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> pushstack;
        
        int curr_idx=0;
        for(auto num: pushed){
            pushstack.push(num);
            
            while( pushstack.size() and popped[curr_idx ] == pushstack.top())
                pushstack.pop(), ++curr_idx;
            
        }
        
        return pushstack.empty();
    }
};