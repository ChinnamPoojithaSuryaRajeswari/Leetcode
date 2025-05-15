class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int p=groups[0];
        vector<string>ans;
        for(int i=0;i<groups.size();i++){
            if(p==groups[i]){
                ans.push_back(words[i]);
                p=!p;
            }
        }
        return ans;
    }
};