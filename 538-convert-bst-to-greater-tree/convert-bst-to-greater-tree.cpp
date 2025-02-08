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
    void inorder(TreeNode* root,vector<int> &vec){
        if(!root)return;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    void solve(int &index,TreeNode* root,vector<int> &vec){
        if(!root)return;
        solve(index,root->left,vec);
        root->val = vec[index];
        index++;
        solve(index,root->right,vec);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<int>vec;
        inorder(root,vec);
        int val = 0;
        int s = accumulate(vec.begin(),vec.end(),0);
        for(int i = 0 ; i < vec.size() ; i++){
            int res = vec[i];
            vec[i] = s-val;
            val += res;
            // cout<<vec[i]<<" ";
        }
        int indx=0;
        for(int i = 0 ; i < vec.size() ; i++)cout<<vec[i]<<" ";
        solve(indx,root,vec);
        return root;
    }
};