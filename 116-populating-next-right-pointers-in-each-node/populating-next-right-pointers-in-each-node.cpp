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
            int sze = q.size();
            Node* back = NULL;
            while(sze){
                Node* prev = q.front();
                q.pop();
                if(back == NULL){
                    back = prev;
                }
                else{
                    back->next = prev;
                    back = prev;
                }
                if(prev->left){
                    q.push(prev->left);
                }
                if(prev->right){
                    q.push(prev->right);
                }
                sze--;
            }
        }
        return root;
    }
};