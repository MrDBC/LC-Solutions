class Solution {
public:
    // intuition: do the xor of all numbers
    // what we get is the xor of the 2 unique no.s
    // we know that xor of 2 unique no.s cant be 0 , right?
    // now we modify the xor such that we only have the rightmost
    // bit set( rightmostbitset_num)
    // now we traverse the array all again, and if the no. is set
    // at the bit position as (rightmostbitset_num), we xor it will 'intA'
    // otherwise we xor it with 'intB'

    vector<int> singleNumber(vector<int>& nums) {
        long int aXorb = 0; // the result of a xor b;
        for (auto item : nums) 
            aXorb ^= item;
        
        long int rightmostbitset_num = (aXorb & (aXorb - 1)) ^ aXorb; // the last bit that a diffs b
        long int intA = 0, intB = 0;
        
        for (auto item : nums) {
            // based on the last bit, group the items into groupA(include a) and groupB
            if (item & rightmostbitset_num) 
                intA = intA ^ item;
            else 
                intB = intB ^ item;
        }
        return vector{(int)intA, (int)intB};
    }

};