class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n= heights.size();
        
        // the stack is a strictly monotonic increasing one
        stack<int> st;
        
        vector<int> res(n);
        for(int i=n-1; i>=0 ; i--){
            
            // pop all the heights having heights <= current height
            // now the total heights we can see is the no. of popped 
            // heights 
            // case 1: +1 , if the stack is non empty, after popping
            // case 2: +0 , if the stack is empty , after popping
            int howmany=0;
            while( !st.empty() and st.top()<= heights[i] and ++howmany)
                st.pop();
                
            res[i]= howmany+ (!st.empty()? 1: 0);

            // push current height into the stack
            st.push(heights[i]);
        }
        
        return res;
    }
};