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
public:
    void rec(Node* root,vector<int>& vec){
        if(root==NULL) return ;
        for(int i=0;i<root->children.size();i++){
            rec(root->children[i],vec);
            vec.push_back(root->children[i]->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int>vec;
        rec(root,vec);
        if(root){
        vec.push_back(root->val);
        }
        return vec;
    }
};