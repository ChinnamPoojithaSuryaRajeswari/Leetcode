class Solution {
public:
    void solve(vector<vector<int>>& matrix,vector<vector<int>>& vec,int i,int j){
        for(int k=0;k<matrix[0].size();k++){
            vec[i][k] = 0;
        }
        for(int k=0;k<matrix.size();k++){
            vec[k][j] = 0;
        }
        return;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>vec;
        vec = matrix;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    solve(matrix,vec,i,j);
                }
            }
        }
        matrix = vec;
    }
};