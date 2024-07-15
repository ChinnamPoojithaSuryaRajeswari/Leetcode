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
    void rec(TreeNode*root ,map<int,vector<int>>& mpp){
        if(root==NULL) return;
        if(mpp[root->val][0]==-1 and mpp[root->val][1]==-1) return;
        if(mpp[root->val][0]==-1){
            TreeNode* NN2 = new TreeNode(mpp[root->val][1]);
            root->right = NN2;
        }
        else if(mpp[root->val][1]==-1){
            TreeNode* NN1 = new TreeNode(mpp[root->val][0]);
            root->left = NN1;
        }
        else{
            TreeNode* NN1 = new TreeNode(mpp[root->val][0]);
            root->left = NN1;
            TreeNode* NN2 = new TreeNode(mpp[root->val][1]);
            root->right = NN2;
        }
        rec(root->left,mpp);
        rec(root->right,mpp);
    }
    TreeNode* createBinaryTree(vector<vector<int>>& description) {
        map<int,vector<int>>mpp;
        map<int,int>mp;
         for(int i=0;i<description.size();i++){
             mp[description[i][1]]+=1;
             mpp[description[i][0]].push_back(-1);
             mpp[description[i][0]].push_back(-1);
             mpp[description[i][1]].push_back(-1);
             mpp[description[i][1]].push_back(-1);
             if(description[i][2]==0){
                 mpp[description[i][0]][1]=description[i][1];
             }
             else{
                 mpp[description[i][0]][0]=description[i][1];
             }
        }
        int r;
        for(auto it:mpp){
            if(mp[it.first]==0){
                r = it.first;
            }
        }
        TreeNode* NN = new TreeNode(r);
        rec(NN,mpp);
        return NN;
    }
};