/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root->val==p->val || root->val==q->val){
            return root;
        }
        TreeNode* lft = lowestCommonAncestor(root->left,p,q);
        TreeNode* rt = lowestCommonAncestor(root->right,p,q);
        if(lft==NULL){
            return rt;
        }
        else if(rt==NULL){
            return lft;
        }
        return root;
    }
};