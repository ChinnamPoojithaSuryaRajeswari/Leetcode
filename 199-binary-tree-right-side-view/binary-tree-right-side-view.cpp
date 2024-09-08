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
    void dfs(TreeNode* root,int index,map<int,int>& mpp,vector<int>& vec){
        if(root==NULL) return;
        if(mpp[index]==0){
            mpp[index]+=1;
            vec.push_back(root->val);
        }
        dfs(root->right,index+1,mpp,vec);
        dfs(root->left,index+1,mpp,vec);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>vec; 
        map<int,int>mpp;
        dfs(root,0,mpp,vec);
        return vec;
    }
};