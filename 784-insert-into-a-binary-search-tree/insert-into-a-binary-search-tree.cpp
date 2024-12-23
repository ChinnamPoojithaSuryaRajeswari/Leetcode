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
        if(root==NULL){
            TreeNode* nn = new TreeNode(val);
            return nn;
        }
        TreeNode* temp = root;
        while(1){
            if(root->val > val){
                if(root->left==NULL){
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else if(root->val < val){
                if(root->right==NULL){
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        if(root->val > val){
            TreeNode* nn = new TreeNode(val);
            root->left=nn;
        }
        else if(root->val < val){
            TreeNode* nn = new TreeNode(val);
            root->right = nn;
        }
        return temp;
    }
};