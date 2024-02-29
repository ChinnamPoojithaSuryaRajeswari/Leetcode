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
    void treee(TreeNode* root,map<int,vector<int>>&mp,int level){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL){
                mp[level].push_back(root->val);
            return;
        }
        mp[level].push_back(root->val);
        treee(root->left,mp,level+1);
        treee(root->right,mp,level+1);
    }
    bool isEvenOddTree(TreeNode* root) {
        map<int,vector<int>>mp;
        treee(root,mp,0);
        int level=0;
        for(auto it:mp){
            if(level%2==0){
                for(int i=0;i<it.second.size()-1;i++){
                    // cout<<it.second[i]<<" "<<it.second[i+1];
                    if(it.second[i]>=it.second[i+1]  or it.second[i]%2==0 or it.second[i+1]%2==0){
                        // cout<<it.second[i]<<" "<<it.second[i+1];
                        return false;
                    }
                }
                if(it.second[it.second.size()-1]%2==0) return false;
            }
            else{
                for(int i=0;i<it.second.size()-1;i++){
                    // cout<<it.second[i]<<" ";
                    if(it.second[i]<=it.second[i+1] or it.second[i]%2==1 or it.second[i+1]%2==1){
                        return false;
                    }
                }
                if(it.second[it.second.size()-1]%2==1) return false;
            }
            level+=1;
        }
        return true;
    }
};