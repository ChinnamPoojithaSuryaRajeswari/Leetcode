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
    int rec(TreeNode* root,int & maxi){
        if(root==NULL) return 0;
        if(root->left==NULL and root->right==NULL) return 1;
        int lft = 1+rec(root->left,maxi);
        int rt = 1+rec(root->right,maxi);
        maxi = max(maxi,lft+rt);
        return max(lft,rt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        rec(root,maxi);
        if(maxi==INT_MIN) return 0;
        return maxi-2;
    }
};