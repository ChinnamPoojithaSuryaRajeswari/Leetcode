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
    void help(TreeNode* root,int &asnwer,int maxi){
        if(root==NULL)return;
        if(maxi <= root->val){
            asnwer+=1;
            cout<<root->val<<" ";
        }
        help(root->left,asnwer,max(maxi,root->val));
        help(root->right,asnwer,max(maxi,root->val));
    }
    int goodNodes(TreeNode* root) {
        int answer=0;
        help(root,answer,INT_MIN);
        return answer;
    }
};