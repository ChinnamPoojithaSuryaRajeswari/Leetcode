class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,pair<int,int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mp[mat[i][j]]={i,j};
            }
        }
        int m=mat.size(),n=mat[0].size();
        vector<int>r(m,0);
        vector<int>c(n,0);
        for(int i=0;i<arr.size();i++){
            r[mp[arr[i]].first]+=1;
            c[mp[arr[i]].second]+=1;
            if(r[mp[arr[i]].first]==n or c[mp[arr[i]].second]==m){
                return i;
            }
        }
        return 0;
    }
};