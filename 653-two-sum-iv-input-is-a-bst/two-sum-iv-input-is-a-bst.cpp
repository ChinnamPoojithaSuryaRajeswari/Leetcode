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
    void cal(TreeNode* root,int target,bool& flag,TreeNode* res){
        if(root==NULL){
            return;
        }
        if(root->val==target and root!=res){
            flag = true;
            return ;
        }
        if(root->val > target){
            root=root->left;
        }
        else{
            root=root->right;
        }
        cal(root,target,flag,res);
    }
    void rec(TreeNode* root,int k,bool & flag,TreeNode* wes){
        if(root==NULL or flag==true) return;
        cal(wes,k-root->val,flag,root);
        rec(root->left,k,flag,wes);
        rec(root->right,k,flag,wes);
    }
    bool findTarget(TreeNode* root, int k) {
        bool flag=false;
        rec(root,k,flag,root);
        return flag;
    }
};