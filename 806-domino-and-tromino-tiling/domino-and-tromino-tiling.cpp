class Solution {
public:
    int numTilings(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;
        long long mod=1e9+7;
        vector<long long>dp(n,0);
        dp[0]=1;
        dp[1]=2;
        dp[2]=5;
        for(int i = 3 ; i < n ; i++){
            long long t=dp[i-1];
            t=((2%mod)*(t%mod))%mod;
            t=(t%mod + (dp[i-3]%mod))%mod;
            dp[i]=t;
        }
        return dp[n-1];
    }
};