class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        // 101
        // 110
        // 111
        int shift=1;
        while( left != right){
            left>>=1;
            right>>=1;
            shift<<=1;
        }
        
        return left*shift;
    }
};