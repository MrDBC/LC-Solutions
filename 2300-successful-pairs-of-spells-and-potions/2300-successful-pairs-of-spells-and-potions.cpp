class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n= spells.size(), m = potions.size();
        
        // sort  the potions vector, 
        sort(begin(potions), end(potions));
        
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            
            // and for every spell, find the least factor we need
            // which when multpiled with spell ( ie., spell * factor) >= success
            int spell= spells[i];
            long long factor = (success+spell-1)/spell;
            
            // 5 8 8
            auto itr = lower_bound(begin(potions), end( potions), factor);
            ans[i]= potions.end()- itr; // count of such factors
        }
        
        return ans;
    }
};