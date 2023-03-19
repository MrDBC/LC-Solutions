class TrieNode{
public:
    bool isend;
    TrieNode* children[26];
    TrieNode(){
        memset(children, NULL, sizeof(children));
        isend= false;
    }
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root= new TrieNode();
    }
    
    void addWord(string word) {
        auto temp = root;
        
        for(auto ch: word){
            if( !temp->children[ch-'a'])
                temp->children[ch-'a'] = new TrieNode();
            
            temp = temp->children[ch-'a'];
        }
        temp->isend= true;
    }
    
    bool searchdfs(string word, int idx, TrieNode* node){
        if( idx== word.size())
            return node->isend;
        char ch= word[idx];

        if( ch=='.'){
            for(int i=0;i <26; i++){
                if( node->children[i] && searchdfs(word, idx+1, node->children[i]))
                    return true;
            }
            return false;
        }
        else{
            if( node->children[ch-'a'])
                return searchdfs( word, idx+1, node->children[ch-'a'] );
            else
                return false;
        }
    }
        

    bool search(string word) {
    
        return searchdfs(word,0, root);    
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */