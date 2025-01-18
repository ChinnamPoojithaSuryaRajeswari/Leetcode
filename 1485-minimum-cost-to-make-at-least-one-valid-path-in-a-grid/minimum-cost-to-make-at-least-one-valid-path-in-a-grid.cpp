class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
       vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(), INT_MAX));
       queue<pair<int,int>>q;
       q.push({0,0});
       dp[0][0]=0;
       int val=0,ans=INT_MAX;
       while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(i+1<grid.size()){
            val = dp[i][j]+(grid[i][j]==3 ? 0:1);
            if(val < dp[i+1][j]){
                dp[i+1][j]=val;
                q.push({i+1,j});
            }
        }
        if(i-1>=0){
            val = dp[i][j]+(grid[i][j]==4 ? 0:1);
            if(val < dp[i-1][j]){
                dp[i-1][j]=val;
                q.push({i-1,j});
            }
        }
        if(j+1<grid[0].size()){
            val = dp[i][j]+(grid[i][j]==1 ? 0:1);
            if(val < dp[i][j+1]){
                dp[i][j+1]=val;
                q.push({i,j+1});
            }
        }
        if(j-1>=0){
            val = dp[i][j]+(grid[i][j]==2 ? 0:1);
            if(val < dp[i][j-1]){
                dp[i][j-1]=val;
                q.push({i,j-1});
            }
        }
       }
       return dp[grid.size()-1][grid[0].size()-1];
    }
};