class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int s=0;
        for(int i=0;i<m;i++){
            s+=grid[i][0]; 
            dp[i][0]=s;
        }
        s=0;
        for(int i=0;i<n;i++){
            s+=grid[0][i]; 
            dp[0][i]=s;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(grid[i][j]+dp[i-1][j],grid[i][j]+dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};