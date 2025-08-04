class Solution {
public:
    int fun(vector<vector<int>>&dp,int i,int j,int val,vector<int>&nums){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=0,b=0,c=0;
        if(nums[i]+nums[i+1]==val){
            a=1+fun(dp,i+2,j,val,nums);
        }
        if(nums[j]+nums[j-1]==val){
            b=1+fun(dp,i,j-2,val,nums);
        }
        if(nums[i]+nums[j]==val){
            c=1+fun(dp,i+1,j-1,val,nums);
        }
        return dp[i][j]=max(a,max(b,c));
    }
    int maxOperations(vector<int>& nums) {
        int ans=1,n=nums.size();
        if(n<=3) return 1;
        int x=0,y=0,z=0;
        for(int i=0;i<3;i++){
            vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
            if(i==0){
                x=fun(dp,2,n-1,nums[0]+nums[1],nums);
            }
            else if(i==1){
                y=fun(dp,0,n-3,nums[n-1]+nums[n-2],nums);
            }
            else{
                z=fun(dp,1,n-2,nums[0]+nums[n-1],nums);
            }
        }
        ans+=max(x,max(y,z));
        return ans;
    }
};