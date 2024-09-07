/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(TreeNode* root, ListNode* temp){
        // base case
        bool p,m;
        if(root == NULL) return false;
        if(root->val!=temp->val) return false;
        if(temp->next==NULL){
            return true;
        }
        p=false;
        m=false;
        if(root->left && temp->next){
            p = dfs(root->left,temp->next);
        }
        if(root->right && temp->next){
            m = dfs(root->right,temp->next);
        }
        return m or p;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL) return false;
        if(root->val==head->val){
            if(dfs(root,head)){
                return true;
            }
        }
        return isSubPath(head,root->left) or isSubPath(head,root->right);
    }
};