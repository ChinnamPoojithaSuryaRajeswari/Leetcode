class Solution {
public:
    void rotate(vector<vector<int>>& matrix){
        int nums[matrix.size()][matrix[0].size()];
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                nums[j][matrix.size()-1-i]=matrix[i][j];
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                matrix[i][j]=nums[i][j];
            }
        }
    }
};