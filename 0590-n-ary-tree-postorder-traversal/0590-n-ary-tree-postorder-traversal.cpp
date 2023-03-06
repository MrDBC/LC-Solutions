/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> res;
public:
    void dfs(Node* root){
        if( !root)
            return;
        
        // call the all subtrees of root ist
        for(int i=0; i<root->children.size(); i++){
            dfs( root->children[i]);
        }
        // push current root into the vector
        res.push_back(root->val);
        
        // return 
    }
    vector<int> postorder(Node* root) {
        
        dfs( root);
        return res;
        
    }
};