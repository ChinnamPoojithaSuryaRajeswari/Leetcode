class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]==i){
                    dp[i]=1;
                }
                if(coins[j]<i){
                    if(dp[i-coins[j]]!=INT_MAX){
                        dp[i]=min(dp[i],dp[i-coins[j]]+1);
                    }
                }
            }
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        else{
            return dp[amount];
        } 
    }
};