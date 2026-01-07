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
    int mod = 1e9+7;

long long dfs(long long &total, TreeNode* root, long long &ans) {
        if (!root) return 0;
        long long left = dfs(total, root->left, ans);
        long long right = dfs(total, root->right, ans);
        long long sum = root->val + left + right;
        long long vallly = sum * (total - sum);  
        ans = max(ans, vallly);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        long long total = 0, ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            total += q.front()->val;
            TreeNode* rt = q.front();
            q.pop();
            if (rt->left) q.push(rt->left);
            if (rt->right) q.push(rt->right);
        }
        dfs(total, root, ans);
        return ans % mod;  
    }
};