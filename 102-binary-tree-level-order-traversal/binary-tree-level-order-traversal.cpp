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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        if(!root)return{};
        vector<vector<int>>answer;
        while(!q.empty()){
            int sze = q.size();
            vector<int>res;
            while(sze--){
                if(q.front()->left!=NULL){
                    q.push(q.front()->left);
                }
                if( q.front()->right!=NULL){
                    q.push(q.front()->right);
                }
                res.push_back(q.front()->val);
                q.pop();
            }
            answer.push_back(res);
        }
        return answer;
    }
};