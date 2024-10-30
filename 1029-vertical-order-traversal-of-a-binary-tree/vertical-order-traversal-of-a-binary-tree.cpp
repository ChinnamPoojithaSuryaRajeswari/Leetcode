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
    void rec(TreeNode* root,map<int,map<int,vector<int>>>& mpp,int level,int col){
        if(root==NULL) return;
        mpp[level][col].push_back(root->val);
        rec(root->left,mpp,level-1,col+1);
        rec(root->right,mpp,level+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>vec;
        map<int,map<int,vector<int>>>mpp;
        int level=0,col=0;
        rec(root,mpp,level,col);
        for(auto it:mpp){
            vector<int>t;
            for(auto i:it.second){
                sort(i.second.begin(),i.second.end());
                for(auto j:i.second){
                    t.push_back(j);
                }
            }
            vec.push_back(t);
            t.clear();
        }
        return vec;
    }
};