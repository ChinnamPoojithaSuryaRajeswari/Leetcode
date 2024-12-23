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
    void rec(vector<int>& inorder,map<int,TreeNode*>& mpp,TreeNode* root){
        if(root == NULL) return;
        rec(inorder,mpp,root->left);
        mpp[root->val]=root;
        inorder.push_back(root->val);
        rec(inorder,mpp,root->right);
    }
    void recoverTree(TreeNode* root) {
        vector<int>inorder;
        map<int,TreeNode*>mpp;
        rec(inorder,mpp,root);
        int x=0;
        for(auto it:mpp){
            if(inorder[x]!=it.second->val){
                int res = mpp[inorder[x]]->val;
                mpp[inorder[x]]->val = it.second->val;
                it.second->val = res;
                break;
            }
            x+=1;
        }
    }
};