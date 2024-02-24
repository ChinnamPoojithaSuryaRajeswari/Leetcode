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
    // void inorder1(TreeNode* root,vector<int>&indr1){
    //     if(root==NULL){indr1.push_back(0);
    //         return;}
    //     inorder1(root->left,indr1);
    //     indr1.push_back(root->val);
    //     inorder1(root->right,indr1);
    // }
    // void inorder2(TreeNode* root,vector<int>&indr2){
    //     if(root==NULL){indr2.push_back(0);
    //                    return;}
    //     inorder2(root->left,indr2);
    //     indr2.push_back(root->val);
    //     inorder2(root->right,indr2);
    // }
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     vector<int>indr1;
    //     vector<int>indr2;
    //     inorder1(p,indr1);
    //     inorder2(q,indr2);
    //     if(indr1.size()!=indr2.size()){
    //         return false;
    //     }
    //     if(indr1.size()!=indr2.size()){return false;}
    //     for(int i=0;i<indr2.size();i++){
    //         cout<<indr2[i]<<" ";
    //     }
    //     cout<<endl;
    //     for(int i=0;i<indr1.size();i++){
    //         cout<<indr1[i]<<" ";
    //     }
    //     for(int i=0;i<indr1.size();i++){
    //         if(indr1[i]!=indr2[i]){return false;}
    //     }
    //     return true;
    void Same(TreeNode* p,TreeNode* q,int &flag){
        if(p == NULL && q == NULL){
            return;
        }
        if(p == NULL && q != NULL){
            flag = 1;
            return;
        }
        if(p != NULL && q == NULL){
            flag = 1;
            return;
        }
        if(p != NULL && q != NULL){
            if(p->val != q->val){
                flag = 1;
                return;
            }
        }
        Same(p->left,q->left,flag);
        Same(p->right,q->right,flag);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int flag = 0;
        Same(p,q,flag);
        if(flag == 1){
            return false;
        }
        else{
            return true;
        }
    }
};