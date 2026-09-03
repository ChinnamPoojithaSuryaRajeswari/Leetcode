class Solution {
public:
    bool solve(vector<int>& nums,int target,int i,vector<vector<int>>&dp){
        if(i==0)return nums[i]==target;
        if(target==0)return true;
        if(dp[i][target]!=-1)return dp[i][target]==1;
        bool unpick = solve(nums,target,i-1,dp);
        bool pick = false;
        if(target >= nums[i]){
            pick = solve(nums,target-nums[i],i-1,dp);
        }
        dp[i][target] = pick|unpick;
        return dp[i][target];
    }
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(int i=0;i<nums.size();i++)target+=nums[i];
        if(target%2)return false;
        target = target/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return solve(nums,target,nums.size()-1,dp);
    }
};