class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int mod = 1e9+7;
        long long ans=1,cons=0,i=0;
        while(i<nums.size()){
            if(nums[i]==1)break;
            i++;
        }
        if(i==nums.size())return 0;
        i++;
        while(i<nums.size()){
            if(nums[i]==1){
                i++;
                cons++;
                ans = ((ans%mod)*(cons%mod))%mod;
                cons=0;
            }
            else{
                cons++;
                i++;
            }
        }
        return ans;
    }
};