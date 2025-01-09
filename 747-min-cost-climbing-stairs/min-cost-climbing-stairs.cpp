class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),INT_MAX);
        dp[0]=cost[0];
        dp[1]=cost[1];
        if(cost.size()==0)return cost[0];
        for(int i=2;i<cost.size();i++){
            dp[i]=min(cost[i]+dp[i-1],cost[i]+dp[i-2]);
        }
        return min(dp[dp.size()-1],dp[dp.size()-2]);
    }
};