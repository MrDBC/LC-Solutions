class Solution {
    vector<string> res;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us;
        for(auto str:wordDict)
            us.insert(str);
    
        dfs( s, 0, "", us);
        return res;
    }
    
    // cnt is the count of spaces we insert in our sentence
    void dfs( string& s, int idx, string sentence, unordered_set<string>& us ){
       
        if( idx== s.size() ){
            sentence.pop_back();
            res.push_back(sentence);
            return;
        }
        
        string newword="";
        for(int i=idx; i<s.size(); i++){
            newword+= s[i];
            
            if( us.count(newword)){
                dfs(s, i+1, sentence+newword+" ", us);
            }
        }
    }
};
