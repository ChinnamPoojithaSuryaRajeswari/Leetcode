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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>qu;
        qu.push(root);
        int cnt=0;
        vector<vector<int>>ans;
        while(!qu.empty()){
            vector<int>res;
            int k = qu.size();
            while(k){
                k--;
                TreeNode* temp = qu.front();
                res.push_back(temp->val);
                if(temp->left){
                    qu.push(temp->left);
                }
                if(temp->right){
                    qu.push(temp->right);
                }
                qu.pop();
            }
            if(cnt%2==1){
                reverse(res.begin(),res.end());
            }
            cnt++;
            ans.push_back(res);
        }
        return ans;
    }
};