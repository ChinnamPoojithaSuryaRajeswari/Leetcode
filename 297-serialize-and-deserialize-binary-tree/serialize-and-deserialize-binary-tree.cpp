/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(!root)return "";
        queue<TreeNode*>q;
        ans += to_string(root->val);
        ans+=" ";
        q.push(root);
        while(!q.empty()){
            int sze = q.size();
            while(sze--){
                TreeNode* res = q.front();
                q.pop();
                if(res->left){
                    ans += to_string(res->left->val);
                    ans += " ";
                    q.push(res->left);
                }
                else{
                    ans += "N ";
                }
                if(res->right){
                    ans += to_string(res->right->val);
                    ans += " ";
                    q.push(res->right);
                }
                else{
                    ans += "N ";
                }
            }
        }
        cout<<ans<<" ";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0 || data[0]=='N')return NULL;
        vector<string> info;
        stringstream ss(data);
        string word;
        while(ss >> word){
            info.push_back(word);
        }
        int res = stoi(info[0]);
        TreeNode* root = new TreeNode(res);
        queue<TreeNode*>q;
        q.push(root);
        int i=0;
        while(!q.empty() && i < info.size()){
            TreeNode* curr = q.front();
            q.pop();
            if((2*i)+1<info.size() and info[(2*i)+1] !="N"){
                res = stoi(info[(2*i)+1]);
                TreeNode* lft = new TreeNode(res);
                curr->left = lft;
                q.push(lft);
            }
            if((2*i)+2 <info.size() and info[(2*i)+2]!="N"){
                res = stoi(info[(2*i)+2]);
                TreeNode* rgt = new TreeNode(res);
                curr->right = rgt;
                q.push(rgt);
            }
            i+=1;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));