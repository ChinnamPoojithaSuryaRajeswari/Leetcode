class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,pair<int,int>>mpp;
        vector<int>rows(mat.size(),0);
        vector<int>col(mat[0].size(),0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mpp[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
            rows[mpp[arr[i]].first]++;
            col[mpp[arr[i]].second]++;
            if(rows[mpp[arr[i]].first]==mat[0].size()){
                return i;
            }
            
            if(col[mpp[arr[i]].second]==mat.size()){
                return i;
            }
        }
        return -1;
    }
};