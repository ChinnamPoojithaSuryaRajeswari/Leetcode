class Solution {
public:
    bool fun(vector<vector<int>>&dp,vector<int>&nums,int target,int index){
        if(target==0)return true;
        if(index==0){
            return nums[index]==target;
        }
        if(dp[target][index]!=-1)return dp[target][index];
        bool up = fun(dp,nums,target,index-1);
        bool p = false;
        if(target >= nums[index]){
            p=fun(dp,nums,target-nums[index],index-1);
        }
        dp[target][index]= up || p;
        return dp[target][index];
    }
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums. begin(), nums. end(), 0);
        if(target%2)return false;
        target = target/2; 
        vector<vector<int>>dp(target+1,vector<int>(nums.size(),-1));
        int index = nums.size()-1;
        return fun(dp,nums,target,index);
    }
};