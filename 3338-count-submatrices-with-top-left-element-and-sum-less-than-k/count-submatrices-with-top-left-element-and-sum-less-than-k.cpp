class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans=0;
        if(grid[0][0]<=k)ans++;
        else return 0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
        dp[0][0] = grid[0][0];
        for(int i=1;i<grid.size();i++){
            dp[i][0] = dp[i-1][0]+grid[i][0];
            if(dp[i][0]<=k)ans++;
        }
        for(int i=1;i<grid[0].size();i++){
            dp[0][i] = grid[0][i]+dp[0][i-1];
            if(dp[0][i]<=k)ans++;
        }
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1]+grid[i][j]-dp[i-1][j-1];
                if(dp[i][j]<=k)ans++;
            }
        }
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};