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
    int rec(TreeNode* root,bool & flag){
        if(root==NULL){
            return 0;
        }
        if(root->right==NULL and root->left==NULL){
            return 1;
        }
        int lft = 1+rec(root->left,flag); 
        int rt =  1+rec(root->right,flag);
        if(abs(lft-rt)>1) flag=false;
        return max(lft,rt);
    }
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        rec(root,flag);
        return flag;
    }
};