


class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int  n= arr.size();

        stack<int> stk_left, stk_right;

        vector<int> left(n), right(n);

        for(int i=0; i<n; i++){

            // >= to deal with duplicates on the left side
            // we cant do a >= check for the right side as well,
            // as we will be considering duplicate subarrays as well
            // so u can do a >= check  either for the left or right NLE
            while( !stk_left.empty() and arr[stk_left.top()] >= arr[i])
                stk_left.pop();

            left[i]= (!stk_left.empty())? (i- stk_left.top()): i+1;
            stk_left.push(i);
        }

        for(int i=n-1; i>=0; i--){
            while( !stk_right.empty() and arr[stk_right.top()] > arr[i])
                stk_right.pop();

            right[i]= (!stk_right.empty())? (stk_right.top()- i): n-i;
            stk_right.push(i);
        }


        int mod= 1e9+ 7, sum=0;
        for(int i=0; i<n;i++)
            sum= (sum+ ((long long)arr[i]*left[i]*right[i])%mod)%mod;
        
        return sum;
    }
};