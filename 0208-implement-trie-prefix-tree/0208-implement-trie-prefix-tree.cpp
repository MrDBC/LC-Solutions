class TrieNode{
    
public:
    TrieNode* children[26];
    bool end;
    TrieNode(){
        memset(children, NULL, sizeof(children));
        end= false;
    }    
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie(){
        clear(root);
    }
    void clear(TrieNode* root){
        for(int i=0; i<26; i++)
            if( root->children[i] != nullptr)
                clear(root->children[i]);
        
        delete root;
    }
    
    void insert(string word) {
        auto temp = root;
        for(auto c: word){
            if( !temp->children[c-'a'])
                temp->children[c-'a']= new TrieNode();
            
            temp = temp->children[c-'a'];
            
        }
        temp->end = true;
    }
    
    bool search(string word) {
        auto temp =root;
        for(auto c: word){
            cout<<c;
            if( temp->children[c-'a'])
                temp = temp->children[c-'a'];
            else
                return false;
        }
        cout<<endl;
        if( temp->end == true)
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) {
        auto temp =root;
        for(auto c: prefix){
            if( temp->children[c-'a'])
                temp = temp->children[c-'a'];
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */