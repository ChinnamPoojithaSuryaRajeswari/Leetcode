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
    void inorder(TreeNode* root,int& cnt){
        if(root==NULL)return;
        if(root->left==NULL and root->right==NULL){
            cnt+=1;
            return;
        }
        cnt+=1;
        inorder(root->left,cnt);
        inorder(root->right,cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt=0;
        inorder(root,cnt);
        return cnt;
    }
};