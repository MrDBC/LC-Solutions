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
    TrieNode* root, *node;
public:
    WordDictionary() {
        root= new TrieNode();
        node = root;
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

    bool search(string word){
        return searchdfs(word, root);
    }
    bool searchdfs(string word, TrieNode* node ) {
        
        for(int i=0; i<word.size(); i++){
            char ch=word[i];
            if( ch=='.'){
                 for(int idx=0;idx <26; idx++)
                    if( node->children[idx] && searchdfs(word.substr(i+1), node->children[idx]))
                        return true;
                return false;
            }
               
            else{
                if( node->children[ch-'a'])
                    node= node->children[ch-'a'] ;
                else
                    return false;
            }
        }
        
        return node and node->isend;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */