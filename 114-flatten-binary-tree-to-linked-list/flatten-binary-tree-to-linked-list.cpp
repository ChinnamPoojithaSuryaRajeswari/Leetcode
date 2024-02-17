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
    void preorder(TreeNode* root,vector<int>&vec){
        if(root==NULL) return;
        vec.push_back(root->val);
        preorder(root->left,vec);
        preorder(root->right,vec);
    }
    void flatten(TreeNode* root) {
        vector<int>vec;
        preorder(root,vec);
        if(vec.size()!=0){
        root->val = vec[0];
        root->left=NULL;
        root->right=NULL;
        TreeNode* temp = root;
        for(int i=1;i<vec.size();i++){
            TreeNode* NN = new TreeNode(vec[i]);
            temp->right = NN;
            temp = temp->right;
        }
        }
    }
};