class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n= nums.size();
        
        // [1,2,3,4,3 | 1,2,3,4,3]
        //          4   2  3  4  0 0
        
        stack<int> st;
        vector<int> res(n, -1);
        
        // we are just doing the same logic as NGE
        // just that we are looping the "array" twice
        for(int i=2*n-1; i>=0; i--){
            
            while( !st.empty() and st.top()<= nums[i%n]){
                st.pop();
            }
            
            if( !st.empty())
                res[i%n]= st.top();
            
            st.push(nums[i%n]);
        }
        
        return res;
    }
};