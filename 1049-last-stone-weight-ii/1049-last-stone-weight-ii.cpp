class Solution {
    vector<vector<int>> dp;
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n= stones.size();
       
        unordered_set<int> us{0};
        
        for(auto stone: stones){
            unordered_set<int> temp;
            
            for(auto x: us)
                temp.insert({x-stone, x+ stone});
            us=temp;
        }
        
        return abs(*min_element(begin(us), end(us), [](int a, int b){
            return abs(a)<abs(b);
        }));
    }
};