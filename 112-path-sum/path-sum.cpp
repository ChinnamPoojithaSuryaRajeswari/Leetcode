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
    void fun(TreeNode* root,int trgt,int ans,int &valu){
        if(root==NULL) return;
        ans+=root->val;
        if(root->left==NULL and root->right==NULL){
            if(trgt == ans){
                valu = 1;
                return;   
            }
        }
        fun(root->left,trgt,ans,valu);
        fun(root->right,trgt,ans,valu);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int valu=0;
        fun(root,targetSum,0,valu);
        if(valu==1) return true;
        return false;
    }
};