class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixCountSpl;
        map<char,int>mpp;
        int s=0;
        mpp['a']=1;
        mpp['e']=1;
        mpp['i']=1;
        mpp['o']=1;
        mpp['u']=1;
        for(int i=0;i<words.size();i++){
            if(mpp[words[i][0]]!=0 and mpp[words[i][words[i].size()-1]]!=0){
                s+=1;
            }
            prefixCountSpl.push_back(s);
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==queries[i][1]){
                if(queries[i][0]==0){
                    ans.push_back(prefixCountSpl[0]);
                }
                else{
                    ans.push_back(prefixCountSpl[queries[i][0]]-prefixCountSpl[queries[i][0]-1]);
                }
            }
            else{
                if(queries[i][0]==0){
                    ans.push_back(prefixCountSpl[queries[i][1]]);
                }
                else{
                    ans.push_back(prefixCountSpl[queries[i][1]]-prefixCountSpl[queries[i][0]-1]);
                }
            }
        }
        return ans;
    }
};