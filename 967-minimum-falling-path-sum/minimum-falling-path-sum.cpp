class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                int x = matrix[i-1][j];
                int p=INT_MAX,r=INT_MAX;
                if(j-1>=0){
                    p=matrix[i-1][j-1];
                }
                if(j+1<matrix[i].size())r=matrix[i-1][j+1];
                matrix[i][j]+=min(x,min(p,r));
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<matrix[0].size();i++)ans=min(ans,matrix[matrix.size()-1][i]);
        return ans;
    }
};