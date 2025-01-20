class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp;
        int ans=INT_MAX;
        for(int i=0;i<triangle.size();i++){
            vector<int>res(i+1,INT_MAX);
            dp.push_back(res);
        }
        dp[0][0]=triangle[0][0];
        for(int i=0;i<triangle.size()-1;i++){
            for(int j=0;j<triangle[i].size();j++){
                dp[i+1][j]=min(triangle[i+1][j]+dp[i][j],dp[i+1][j]);
                dp[i+1][j+1]=min(triangle[i+1][j+1]+dp[i][j],dp[i+1][j+1]);
            }
        }
        for(int i=0;i<dp[dp.size()-1].size();i++)ans=min(ans,dp[dp.size()-1][i]);
        return ans;
    }
};