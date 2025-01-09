class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>dp;
        dp.push_back({1});
        dp.push_back({1,1});
        for(int i=2;i<=rowIndex;i++){
            vector<int>res;
            res.push_back(1);
            for(int j=0;j<i-1;j++){
                res.push_back(dp[i-1][j]+dp[i-1][j+1]);
            }
            res.push_back(1);
            dp.push_back(res);
        }
        return dp[rowIndex];
    }
};