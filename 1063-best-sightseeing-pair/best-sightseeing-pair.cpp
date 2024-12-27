class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = values[0],n=values.size();
        vector<int>dp(n);
        dp[0]=0;
        for(int i=1;i<values.size();i++){
            dp[i]=max(maxi+values[i]-i,dp[i-1]);
            maxi = max(maxi,values[i]+i);
        }
        return dp[n-1];
    }
};