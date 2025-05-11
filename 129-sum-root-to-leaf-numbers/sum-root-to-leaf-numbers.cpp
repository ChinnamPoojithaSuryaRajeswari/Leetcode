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
    void solve(TreeNode* root,int &ans,int val){
        if(!root){
            // ans += val;
            // cout<<val<<endl;
            return;
        }
        if(root->right==NULL and root->left==NULL){
           val = val*10 + root->val;
           ans+=val;
           return;
        }
        val = val*10 + root->val;
        solve(root->left,ans,val);
        solve(root->right,ans,val);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root,ans,0);
        return ans;
    }
};