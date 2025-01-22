class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>>dp(isWater.size(),vector<int>(isWater[0].size(),-1));
        queue<pair<int,int>>q;
        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[i].size();j++){
                if(isWater[i][j]==1){
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            if(i+1<dp.size()){
                if(dp[i+1][j]==-1){
                    dp[i+1][j]=dp[i][j]+1;
                    q.push({i+1,j});
                }
            }
            if(i-1>=0){
                if(dp[i-1][j]==-1){
                    dp[i-1][j]=dp[i][j]+1;
                    q.push({i-1,j});
                }
            }
            if(j-1>=0){
                if(dp[i][j-1]==-1){
                    dp[i][j-1]=dp[i][j]+1;
                    q.push({i,j-1});
                }
            }
            if(j+1<dp[0].size()){
                if(dp[i][j+1]==-1){
                    dp[i][j+1]=dp[i][j]+1;
                    q.push({i,j+1});
                }
            }
            q.pop();
        }
        return dp;
    }
};