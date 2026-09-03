class Solution {
public:
    int minDistance(string word1, string word2) {
        int ans = 0;
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i=1;i<word1.size()+1;i++){
            for(int j=1;j<word2.size()+1;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    ans = max(ans,dp[i][j]);
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return (word1.size()-ans)+(word2.size()-ans);
    }
};