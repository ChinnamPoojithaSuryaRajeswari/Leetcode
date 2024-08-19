/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inordr(TreeNode* root,stack<TreeNode*>& st){
        if(root==NULL) return;
        inordr(root->left, st);
        TreeNode* NN = new TreeNode(root->val);
        st.push(NN);
        inordr(root->right,st);
    }
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*>st;
        inordr(root,st);
        TreeNode* hd = st.top();
        st.pop();
        while(!st.empty()){
            TreeNode* r = st.top();
            r->right=hd;
            st.pop();
            hd = r;
        }
        return hd;
    }
};