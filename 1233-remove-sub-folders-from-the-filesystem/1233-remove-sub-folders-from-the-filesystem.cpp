class TrieNode{
public:
    TrieNode* children[26];
    bool isend;
    TrieNode(){
        memset(children, NULL, sizeof(children));
        isend= false;
    }    
};
class Solution {
    TrieNode* root= new TrieNode();
    vector<string> res;
public:
    bool insert(string folder){
        auto temp = root;
        for(int i=0; i<folder.size(); i++){
            char c= folder[i];
            
            
            
            if( c=='/')
                continue;
            if( !temp->children[c-'a'])
                temp->children[c-'a']= new TrieNode();
            
            temp = temp->children[c-'a'];
            if( temp->isend == true and folder[i+1]=='/' )
                return false;
            
        }
        temp->isend = true;
        return true;
    }
   
    vector<string> removeSubfolders(vector<string>& folder) {
        int n= folder.size();
        sort( begin(folder), end(folder));
        
        for(auto str: folder){
            if( insert(str))
                res.push_back(str);
        }
    
        return res;
    }
};