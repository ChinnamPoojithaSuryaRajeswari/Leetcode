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
    void rec(TreeNode* root,stack<int>& st){
        if(root==NULL) return;
        rec(root->right,st);
        st.push(root->val);
        rec(root->left,st);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        stack<int>st;
        vector<int>vec;
        rec(root,st);
        while(!st.empty()){
            vec.push_back(st.top());
            st.pop();
        }
        return vec;
    }
};