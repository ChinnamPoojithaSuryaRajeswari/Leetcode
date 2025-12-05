class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0,val=0,ans=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        sum-=nums[0];
        val=nums[0];
        for(int i=1;i<nums.size();i++){
            if((abs(sum-val))%2==0)ans++;
            sum-=nums[i];
            val+=nums[i];
        }
        return ans;
    }
};