class Solution {
public:
    int flag =0;
    bool solve(string s1,string s2,string s3,int i,int j,vector<vector<int>>&dp){
        if(i>=s1.size() and j>=s2.size())return true;
        if(i<s1.size() and s2.size()>j and dp[i][j]!=-1)return dp[i][j];
        if(i<s1.size()){
            if(s1[i]==s3[i+j]){
                if(solve(s1,s2,s3,i+1,j,dp))return dp[i][j]=1;
            }
        }
        if(j<s2.size()){
            if(s2[j]==s3[i+j]){
                if(solve(s1,s2,s3,i,j+1,dp))return dp[i][j]=1;
            }
        }
        return dp[i][j]=0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() !=s3.size())return 0;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,s3,0,0,dp);
        // return flag;
    }
};