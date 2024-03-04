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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* nn = new TreeNode(val);
        TreeNode* temp=root;
        if(root==NULL){
            return nn;
        }
        while(root){
            if(val>root->val){
                if(root->right==NULL){
                    root->right=nn;
                    break;
                }
                root=root->right;
            }
            else{
                if(root->left==NULL){
                    root->left=nn;
                    break;
                }
                root=root->left;
            }
        }
        return temp;
    }
};