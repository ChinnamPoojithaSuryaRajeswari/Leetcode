class Solution {
public:
    int help (vector<int>&nums,int i,int target,vector<vector<int>>&dp,int sum){
        if(i == -1) {
            return target == 0;
        }
        if(target < -sum || target > sum)
            return 0;
        if(dp[i][target + sum] != -1)
            return dp[i][target + sum];
        int pickPluss = help(nums, i - 1, target + nums[i], dp, sum);
        int pickMinus = help(nums, i - 1, target - nums[i], dp, sum);
        return dp[i][target + sum] = pickPluss + pickMinus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)sum += nums[i];
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));
        return help(nums, nums.size() - 1, target, dp, sum);
    }
};