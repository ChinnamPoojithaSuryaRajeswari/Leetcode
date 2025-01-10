class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int>mpp;
        for(int i=0;i<words2.size();i++){
            map<char,int>res;
            for(int j=0;j<words2[i].size();j++){
                res[words2[i][j]]++;
                mpp[words2[i][j]]=max(mpp[words2[i][j]],res[words2[i][j]]);
            }
        }
        vector<string>ans;
        for(int i=0;i<words1.size();i++){
            map<char,int>res;
            int flag=0;
            for(int j=0;j<words1[i].size();j++){
                res[words1[i][j]]++;
            }
            for(auto it:mpp){
                if(it.second>res[it.first]){
                    flag=1;
                    break;
                }
            }
            if(flag!=1)ans.push_back(words1[i]);
        }
        return ans;
    }
};