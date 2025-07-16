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
    int help(TreeNode* root,int state,int currlen){
        if(root==NULL)return currlen;
        cout<<currlen<<" ";
        int left,right;
        if(state==0){
            left = help(root->left,0,1);
            right = help(root->right,1,currlen+=1);
        }
        if(state==1){
            left = help(root->left,0,currlen+=1);
            right = help(root->right,1,1);
        }
        return max(left,right);
    }
    int longestZigZag(TreeNode* root) {
        return (max(help(root->left,0,1),help(root->right,1,1)))-1;
    }
};