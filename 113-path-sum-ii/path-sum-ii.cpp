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
    void solve(TreeNode* root,int targetSum,vector<vector<int>> &answer,vector<int> res,int val){
        if(!root)return;
        if(res.size()==0)res.push_back(val);
        if(root->left==NULL and root->right==NULL){
            if(targetSum == root->val){
                res.push_back(root->val);
                answer.push_back(res);
            }
            return;
        }
        res.push_back(root->val);
        solve(root->left,targetSum-root->val,answer,res,val);
        res.pop_back();
        res.push_back(root->val);
        solve(root->right,targetSum-root->val,answer,res,val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>answer;
        if(!root)return answer;
        if(root->left==NULL and root->right==NULL and targetSum==root->val){
            answer.push_back({root->val});
            return answer;
        }
        vector<int>res;
        targetSum -= root->val;
        solve(root->left,targetSum,answer,res,root->val);
        solve(root->right,targetSum,answer,res,root->val);
        return answer;
    }
};