class Solution {
public:
    bool divisorGame(int n) {
        
        // 1 -> lose
        // 2 -> divisiors: 1 win
        // 3 -> divisors : 1 lose
        // 4 -> divisor : 1 (4-1)=3 win
        // 5 -> 1 lose
        // 6 ->1,2 ,3 
        
        return !(n%2);
    }
};