class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size(), groups =0;
        unordered_set<string> visited;
        
        for(int i=0; i<n; i++){
            if(visited.find(strs[i]) == visited.end()){
                dfs( strs[i], strs, visited);
                ++groups;
            }
        }
        
        return groups;
    }   
    void dfs( string curr, vector<string>& strs, unordered_set<string>& visited){
        if( visited.find(curr) != visited.end())
            return;
        
        visited.insert(curr);
        
        for(int i=0; i<strs.size(); i++){
            if( issimilar(curr, strs[i])){
                dfs(strs[i] , strs, visited);
            }
        }
    }
    int issimilar(string& a, string& b){
        int diff=0;
        for(int i=0; i< a.size(); i++){
            if( a[i]!= b[i] and ++diff >2)
                return 0;
        }
        
        return 1;
    }
};