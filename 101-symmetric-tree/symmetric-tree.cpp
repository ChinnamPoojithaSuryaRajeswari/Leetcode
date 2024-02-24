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
    void Sametrre(TreeNode* temp,TreeNode* res,int& flag){
        if(temp==NULL and res==NULL){
            return;
        }
        if(temp==NULL and res!=NULL){
            flag=1;
            return;
        }
        if(temp!=NULL and res==NULL){
            flag=1;
            return;
        }
        if(temp!=NULL and res!=NULL){
            if(temp->val!=res->val){
                flag=1;
                return;
            }
        }
        Sametrre(temp->left,res->right,flag);
        Sametrre(temp->right,res->left,flag);
    }
    bool isSymmetric(TreeNode* root) {
        int flag=0;
        TreeNode* temp = root->left;
        TreeNode* res = root->right;
        Sametrre(temp,res,flag);
        if(flag==1) return false;
        return true;
    }
};