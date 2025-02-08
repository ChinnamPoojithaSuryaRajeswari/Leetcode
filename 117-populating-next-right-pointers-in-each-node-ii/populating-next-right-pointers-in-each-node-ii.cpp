/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* prev = NULL;
            int sze = q.size();
            while(sze--){
                Node* v = q.front();
                if(prev==NULL) prev = v;
                else{
                    prev->next = v;
                    prev = v;
                }
                if(v->left){
                    q.push(v->left);
                }
                if(v->right){
                    q.push(v->right);
                }
                q.pop();
            }
        }
        return root;
    }
};