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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* current;
        TreeNode* parent;
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,root});
        if(root==NULL)return NULL;
        while(!q.empty()){
            current = q.front().first;
            parent = q.front().second;
            q.pop();
            // cout<<"re";
            if(current->val==key){
                // cout<<"SF";
                break;
            }
            if(current->left){
                q.push({current->left,current});
            }
            if(current->right){
                q.push({current->right,current});
            }
        }
        if(q.empty() and current->val!=key)return root;
        if(root==current){
            // cout<<"Dfs";
            if(root->left==NULL)return root->right;
            if(root->right==NULL)return root->left;
            if(root->left==NULL and root->right==NULL)return NULL;
            TreeNode* temp = root;
            temp = temp->right;
            while(temp->left){
                temp = temp->left;
            }
            temp->left = root->left;
            root = root->right;
            return root;
        }
        if(current->left!=NULL and current->right!=NULL){
            TreeNode* temp = current;
            temp = temp->right;
            while(temp->left){
                temp = temp->left;
            }
            temp->left = current->left;
            current->left = NULL;
            if(parent->left==current){
                parent->left = current->right;
            }
            else{
                parent->right = current->right;
            }
            return root;
        }
        if(current->left==NULL and current->right==NULL){
            if(parent->left==current){
                parent->left = NULL;
            }
            else{
                parent->right = NULL;
            }
            return root;
        }
        if(current->left==NULL){
            if(parent->left==current){
                parent->left = current->right;
            }
            else{
                parent->right = current->right;
            }
        }
        if(current->right==NULL){
            if(parent->left==current){
                parent->left = current->left;
            }
            else{
                parent->right = current->left;
            }
        }

        return root;
    }
};