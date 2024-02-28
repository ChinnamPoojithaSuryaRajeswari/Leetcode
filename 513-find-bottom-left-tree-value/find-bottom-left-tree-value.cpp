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
    void btm(TreeNode* root,map<int,vector<int>>&mpp,int l){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL){
            mpp[l].push_back(root->val);
            return;
        }
        btm(root->left,mpp,l+1);
        btm(root->right,mpp,l+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        map<int,vector<int>>mpp;
        btm(root,mpp,0);
        int ans=0;
        for(auto it:mpp){
            ans = it.second[0];
        }
        return ans;
    }
};