class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
          map<int,int>mpp;
          map<int,int>prev;
          vector<int>ans;
          for(int i=0;i<queries.size();i++){
             if(prev[queries[i][0]]!=0){
                if(prev[queries[i][0]]!=queries[i][1]+1){
                    mpp[prev[queries[i][0]]-1]-=1;
                    if(mpp[prev[queries[i][0]]-1]==0){
                        mpp.erase(prev[queries[i][0]]-1);
                    }
                    mpp[queries[i][1]]++;
                    prev[queries[i][0]] = queries[i][1]+1;
                }
             }
             else{
                mpp[queries[i][1]]++;
                prev[queries[i][0]] = queries[i][1]+1;
             }
             ans.push_back(mpp.size());
          }
          return ans;
    }
};