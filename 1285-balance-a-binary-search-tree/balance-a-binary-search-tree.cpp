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
    void inorderTraverse(TreeNode* root,vector<TreeNode*>&sortedArr) {
        if (root == NULL) return;
        inorderTraverse(root->left,sortedArr);
        sortedArr.push_back(root);
        inorderTraverse(root->right,sortedArr);
    }
    TreeNode* sortedArrayToBST(int start, int end,vector<TreeNode*>&sortedArr) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = sortedArr[mid];
        root->left = sortedArrayToBST(start, mid - 1,sortedArr);
        root->right = sortedArrayToBST(mid + 1, end,sortedArr);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>sortedArr;
        inorderTraverse(root,sortedArr);
        return sortedArrayToBST(0, sortedArr.size() - 1,sortedArr);
    }
};