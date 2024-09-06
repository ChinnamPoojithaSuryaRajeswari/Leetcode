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
    bool dfs(TreeNode* root, pair<long long,long long> data){
        if(root==NULL) return true;
        if(root->val>=data.second or root->val<=data.first){
            return false;
        }
        return dfs(root->left,{data.first,root->val}) and dfs(root->right,{root->val,data.second});
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root->left,{LLONG_MIN,root->val}) and dfs(root->right,{root->val,LLONG_MAX});
    }
};