class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,vector<int>>mpp;
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]].push_back(i);
        }
        for(int i=0;i<t.size();i++){
            mp[t[i]].push_back(i);
        }
        vector<vector<int>>ans;
        vector<vector<int>>res;
        map<int,int>req;
        for(int i=0;i<s.size();i++){
            if(req[s[i]]==0){
                req[s[i]]=1;
                ans.push_back(mpp[s[i]]);
            }
        }
        map<int,int>reqt;
         for(int i=0;i<t.size();i++){
            if(reqt[t[i]]==0){
                reqt[t[i]]=1;
                res.push_back(mp[t[i]]);
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i].size()!=res[i].size()) return false;
            for(int j=0;j<ans[i].size();j++){
               if(ans[i][j]!=res[i][j])  return false;
            }
        }
        return true;
    }
};