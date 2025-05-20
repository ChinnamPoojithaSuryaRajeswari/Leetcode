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
    int maxLevelSum(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* temp = root;
        int ansSum=INT_MIN,ansLevel=0,currLevel=0,currSum=0;
        while(!q.empty()){
            int sze=q.size();
            currSum=0;
            currLevel+=1;
            TreeNode* currNode;
            while(sze){
                currNode = q.front();
                q.pop();
                sze-=1;
                currSum+=currNode->val;
                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }
            }
            if(currSum>ansSum){
                ansSum=currSum;
                ansLevel = currLevel;
            }
        }
        if(currSum>ansSum){
            ansSum=currSum;
            ansLevel = currLevel;
        }
        return ansLevel;
    }
};