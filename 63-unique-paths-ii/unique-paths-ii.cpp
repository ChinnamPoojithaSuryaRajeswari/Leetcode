class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        vector<vector<long long>>vec(m,vector<long long>(n,-1));
        vec[0][0]=1;
        long long k =1;
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]!=1){
                vec[i][0]=min(k,vec[i-1][0]);
            }
            else{
                vec[i][0]=0;
            }
        }
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i]!=1){
                vec[0][i]=min(k,vec[0][i-1]);
            }
            else{
                vec[0][i]=0;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]!=1){
                    vec[i][j]=vec[i-1][j]+vec[i][j-1];
                }
                else{
                    vec[i][j]=0;
                }
            }
        }
        return vec[m-1][n-1];
    }
};