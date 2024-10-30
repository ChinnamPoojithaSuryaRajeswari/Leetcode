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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        if(root==NULL)return {};
        vector<int>vec;
        st.push(root);
        while(!st.empty()){
            if(st.top()->left!=NULL and st.top()->left->val!=-200){
                st.push(st.top()->left);
            }
            else{
                vec.push_back(st.top()->val);
                if(st.top()->right!=NULL and st.top()->right->val!=-200){
                    TreeNode* t = st.top()->right;
                    st.top()->val=-200;
                    st.pop();
                    st.push(t);
                }
                else if(st.top()->right==NULL or st.top()->right->val==-200){
                    st.top()->val=-200;
                    st.pop();
                }
            }
        }
        return vec;
    }
};