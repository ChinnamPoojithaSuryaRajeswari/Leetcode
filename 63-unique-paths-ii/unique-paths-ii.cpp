class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int flip=0;
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        for(int i=0;i<obstacleGrid.size();i++){
            int flag=0;
            for(int j=0;j<obstacleGrid[i].size();j++){
                if(i==0){
                    if(obstacleGrid[i][j]==1){
                        flag=1;
                        dp[i][j] = !obstacleGrid[i][j];
                    }
                    else{
                        if(flag){
                            dp[i][j]=0;
                        }
                        else{
                            dp[i][j]=1;
                        }
                    }
                }
                if(j==0){
                    if(obstacleGrid[i][j]==1){
                        flip=1;
                        dp[i][j] = !obstacleGrid[i][j];
                    }
                    else{
                        if(flip){
                            dp[i][j]=0;
                        }
                        else{
                            dp[i][j]=1;
                        }
                    }
                }
            }
        }
        for(int i=1;i<obstacleGrid.size();i++){
            for(int j=1;j<obstacleGrid[i].size();j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i][j-1]+dp[i-1][j];
                }
            }
        }
        
        for(int i=0;i<obstacleGrid.size();i++){
            for(int j=0;j<obstacleGrid[i].size();j++){
                cout<<obstacleGrid[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};