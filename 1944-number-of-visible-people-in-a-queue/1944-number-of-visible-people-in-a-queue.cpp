class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n= heights.size();
        
        // the stack is a strictly monotonic increasing one
        stack<int> st;
        
        vector<int> res(n,0);
        for(int i=n-1; i>=0 ; i--){
    
            if( !st.empty() and st.top()> heights[i])
                res[i]=1;
            
            int howmany=0;
            while( !st.empty() and st.top()<= heights[i]){
                st.pop();
                ++howmany;
            }
            if( howmany>0)
                res[i]= howmany+ (!st.empty()? 1: 0);

            st.push(heights[i]);
        }
        
        return res;
    }
};