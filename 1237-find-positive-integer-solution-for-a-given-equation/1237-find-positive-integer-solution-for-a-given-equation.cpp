/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        
        vector<vector<int>> res;
        for(int x=1; x<=1000; x++){
            
            int ylow=1, yhigh =1000;
            while( ylow <= yhigh){
                int y = (ylow+yhigh)/2;
                
                int output = customfunction.f(x,y);
                if( output == z){
                    res.push_back({x,y});
                    break;
                }
                else if( output < z)
                    ++ylow;
                else
                    yhigh--;
            }
        }
        
        return res;
    }
};