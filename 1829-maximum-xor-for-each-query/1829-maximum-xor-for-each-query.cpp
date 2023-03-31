class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n= nums.size();
        
// intuition:
// let prefix[i] = prefix xor of ist (i+1) numbers
// we can observe that for every prefix[i] ,
// we can always xor it with k(lets say), such that
// we always get (2^maximumBit -1) as the result
        
// Let maximumBit = 3.
// Our choice(k) range will be from [0, 7]. Now, if - 
// XOR is the xor of the all the prefix no.s
// 1. XOR = 1 (001) :  we can choose to xor it with 6 so that maximum xor for query will become '2^maximumBit - 1 = 7'
// 	   ^ 6 (110)
// 	   ----------
// 		    111
			
// 2. XOR = 2 (010) :  we can choose to xor it with 5 so that maximum xor for query will become '2^maximumBit - 1 = 7'
// 	   ^ 5 (101)
// 	   ----------
// 		    111

// 3. XOR = 3 (011) :  we can choose to xor it with 4 
// 	   ^ 4 (100)
// 	   ----------
// 		    111
			
// 4. XOR = 4 (100) :  we can choose to xor it with 3
// 	   ^ 3 (011)
// 	   ----------
// 		    111	
			
// And so on for any other cases, we can choose a value to maximize xor to '2^maximumBit-1'
        
        int prefixxor = 0;
        for(auto num: nums)
            prefixxor^= num;
        
        vector<int> ans(n);
        int target = (1<<maximumBit) -1; // (2^maximumBit) - 1
        
        // we know: (a^b)= c
        // then   : (a^c)= b
        for(int i=0; i<n; i++){
            ans[i] = prefixxor ^ target;
            
            prefixxor^= nums[n-i-1];
        }
        
        return ans;
    }
};