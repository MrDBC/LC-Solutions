class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res = 0;
        
        // for a particular bit position, among all the numbers
        // if we have odd no of 1s, no need to change the bit
        // at that position for any no.s
        
        // for a particular bit position, among all the no.s; 
        // if we have even no of 1s, (we know doing xor of all
        // the no.s will fetch us a 0 at the bit position),
        // so y dont we flip the bit at that position for any 1
        // number
        // now you may ask how can we do it?
        // arrey its very simple, u can do it using this operation
        // nums[i] AND (nums[i] XOR x)
        // lets take an example to see how?
        // nums[i]=3 (011), now flip ist '1' to '0'
        // for this take 'x=1 (001)'
        // 3 & (3 ^ 1) = 011 & (011 ^ 001)
        // = 011 & (010) = 010 (2)
        // we successfully fliped the rightmost '1' in '011' -> '010'
        
        for (int a : nums)
            res |= a;
        return res;
    }
};