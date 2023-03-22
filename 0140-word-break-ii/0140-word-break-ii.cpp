class Solution {
    vector<string> res;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us;
        for(auto str:wordDict)
            us.insert(str);
    
        dfs( s, 0, "", "",0, us);
        return res;
    }
    
    // cnt is the count of spaces we insert in our sentence
    void dfs( string& s, int idx, string word, string sentence, int cnt, unordered_set<string>& us ){
       
        if( idx== s.size() ){
            
            // this confirms we have included every character in our original "s" into our "sentence" as well
            if(sentence.size() == s.size()+cnt){
                sentence.pop_back();
                res.push_back(sentence);
            }
            return;
        }
        
        word+=s[idx];
        
        // our dictionary contains "word", so add it to the sentence, and reinitialize word to empty string
        if( us.find(word) != us.end())
            dfs(s, idx+1, "", sentence+word+" ", cnt+1,us); 
        
        // we want to see other options
        dfs(s, idx+1, word, sentence, cnt, us);
    }
};
