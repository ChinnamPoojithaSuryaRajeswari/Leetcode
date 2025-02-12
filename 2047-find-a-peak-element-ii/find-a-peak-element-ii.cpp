class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int left=-1,right=-1,top=-1,down=-1;
                if(i-1 >=0 ){
                    top = mat[i-1][j];
                }
                if(i+1<mat.size()){
                    down = mat[i+1][j];
                }
                if(j+1<mat[0].size()){
                    right = mat[i][j+1];
                }
                if(j-1 >= 0){
                    left = mat[i][j-1];
                }
                if(mat[i][j] > left and mat[i][j] > right and mat[i][j] > down and mat[i][j] > top){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};