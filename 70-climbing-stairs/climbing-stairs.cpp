class Solution {
public:
    int fibo(int n,vector<int>&dp){
        if(n<=1) return n;
        if(dp[n]!=-1)return dp[n];
        dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+2,-1);
        fibo(n+1,dp);
        return dp[n+1];
    }
};