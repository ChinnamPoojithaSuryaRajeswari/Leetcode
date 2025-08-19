class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long val = 0;
        long long j=0,ans=0;
        while(j<nums.size()){
            if(nums[j]==0){
                val++;
            }
            else{
                if(val!=0){
                    ans = ans+(((val+1)*val)/2);
                }
                val=0;
            }
            j++;
        }
        if(val!=0){
            ans = ans+(((val+1)*val)/2);
        }
        return ans;
    }
};