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
    void dfs(TreeNode* root,unsigned long long val,map<unsigned long long,pair<unsigned long long,unsigned long long>> &visit,int level){
        if(!root)return;
        if(root->left == NULL and root->right == NULL){
            if(visit.find(level)!=visit.end()){
                visit[level].first = min(visit[level].first,val);
                visit[level].second = max(visit[level].second,val);
            }
            else{
                visit[level]={val,val};
            }
            return;
        }
        if(visit.find(level)!=visit.end()){
            visit[level].first = min(visit[level].first,val);
            visit[level].second = max(visit[level].second,val);
        }
        else{
            visit[level]={val,val};
        }
        dfs(root->left,val*2,visit,level+1);
        dfs(root->right,(val*2)+1,visit,level+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ans = 0;
        map<unsigned long long,pair<unsigned long long,unsigned long long>>visit;
        dfs(root,0,visit,0);
        for(auto it:visit){
            ans = max(it.second.second-it.second.first+1,ans);
        }
        return ans;
    }
};

