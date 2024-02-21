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
    int ans=0;
    int valu=0;
    void fun(TreeNode* root,int trgt,int ans){
        if(root==NULL) return;
        ans+=root->val;
        if(root->left==NULL and root->right==NULL){
            if(trgt==ans) {
                valu=1;
                return;
            }
            return;
        }
        // if(trgt<ans) return;
        fun(root->left,trgt,ans);
        fun(root->right,trgt,ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        fun(root,targetSum,ans);
        if(valu==1) return true;
        return false;
    }
};