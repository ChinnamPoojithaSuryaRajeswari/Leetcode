class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string st = s;
        int ans = 0;
        reverse(st.begin(),st.end());
        // cout<<s<<" "<<st<<endl;
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));
        for(int i=1;i<s.size()+1;i++){
            for(int j=1;j<s.size()+1;j++){
                if(s[i-1]==st[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    ans = max(ans,dp[i][j]);
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    ans = max(ans,dp[i][j]);
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return ans;
    }
};