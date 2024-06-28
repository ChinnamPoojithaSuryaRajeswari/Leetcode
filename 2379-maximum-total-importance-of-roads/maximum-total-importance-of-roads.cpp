class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<long long,vector<long long>>mpp;
        for(int i=0;i<roads.size();i++){
            mpp[roads[i][0]].push_back(roads[i][1]);
            mpp[roads[i][1]].push_back(roads[i][0]);
        }
        map<long long,vector<long long>>res;
        long long l = mpp.size();
        for(auto it:mpp){
            res[it.second.size()].push_back(it.first);
        }
        mpp.clear();
        long long k=n-l+1;
        for(auto it:res){
            for(int i=0;i<it.second.size();i++){
                mpp[it.second[i]].push_back(k);
                k+=1;
            }
        }
        long long ans=0;
        for(int i=0;i<roads.size();i++){
            ans=ans+mpp[roads[i][0]][0]+mpp[roads[i][1]][0];
        }
        return ans;
    }
};