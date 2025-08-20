class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==1){
                    if(i==0 or j==0){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j] = 1+(min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}));
                    }
                    ans+=dp[i][j];
                }
            }
        }
        return ans;
    }
};