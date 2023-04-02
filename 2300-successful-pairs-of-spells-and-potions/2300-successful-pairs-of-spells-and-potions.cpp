class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n= spells.size(), m = potions.size();
        
        sort(begin(potions), end(potions));
        
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            int spell= spells[i];
            long long factor = (success+spell-1)/spell;
            
            // 5 8 8
            auto itr = lower_bound(begin(potions), end( potions), factor);
            ans[i]= potions.end()- itr;
        }
        
        return ans;
    }
};