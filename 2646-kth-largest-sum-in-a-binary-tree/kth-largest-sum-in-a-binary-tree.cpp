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
    void rec(TreeNode* root,map<int,long long>& mpp,int level){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL){
            mpp[level]+=root->val;
            return;
        }
        mpp[level]+=root->val;
        rec(root->left,mpp,level+1);
        rec(root->right,mpp,level+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        map<int,long long>mpp;
        rec(root,mpp,0);
        priority_queue<long long>pq;
        for(auto it:mpp){
            pq.push(it.second);
        }
        if(pq.size()<k){
            return -1;
        }
        while(k-1){
            k-=1;
            pq.pop();
        }
        return pq.top();
    }
};