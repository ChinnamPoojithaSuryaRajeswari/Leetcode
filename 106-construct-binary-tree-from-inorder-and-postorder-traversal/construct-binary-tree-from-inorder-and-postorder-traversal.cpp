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
    TreeNode* helper(vector<int>& postorder, unordered_map<int,int>& inordrMap,int postleft, int postright,int inleft, int inright) {
        if (postleft > postright || inleft > inright) return NULL;
        int rootVal = postorder[postright];
        TreeNode* root = new TreeNode(rootVal);
        int inRootIndex = inordrMap[rootVal];
        int leftTreeSize = inRootIndex - inleft;
        root->left = helper(postorder, inordrMap,postleft, postleft + leftTreeSize - 1,inleft, inRootIndex - 1);
        root->right = helper(postorder, inordrMap,postleft + leftTreeSize, postright - 1,inRootIndex + 1, inright);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inordrMap;
        for (int i = 0; i < inorder.size(); i++) {
            inordrMap[inorder[i]] = i;
        }
        return helper(postorder, inordrMap,0, postorder.size() - 1,0, inorder.size() - 1);
    }
};