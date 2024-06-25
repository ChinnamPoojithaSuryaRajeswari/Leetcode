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
    void rec(vector<int>& vec,TreeNode* root){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL){
            vec.push_back(root->val);
            return;
        }
        vec.push_back(root->val);
        rec(vec,root->left);
        rec(vec,root->right);
    }
    void res(TreeNode* root,map<int,int>& mpp){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL){
            root->val=mpp[root->val];
            return;
        }
        root->val=mpp[root->val];
        // cout<<mpp[root->val]<<" ";
        res(root->left,mpp);
        res(root->right,mpp);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> vec;
        rec(vec,root);
        map<int,int>mpp;
        sort(vec.begin(),vec.end());
        int s=0;
        for(int i=0;i<vec.size();i++){
            s+=vec[i];
        }
        vector<int>resi;
        for(int i=0;i<vec.size();i++){
            resi.push_back(s);
            s-=vec[i];
        }
        for(int i=vec.size()-1;i>=0;i--){
            mpp[vec[i]]=resi[i];
        }
        res(root,mpp);
        return root;
    }
};