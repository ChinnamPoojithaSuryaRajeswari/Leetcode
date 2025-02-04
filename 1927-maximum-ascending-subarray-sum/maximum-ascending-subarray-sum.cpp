class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int j=0,ans=0,s=0;
        while(j+1<nums.size()){
            if(nums[j]<nums[j+1]){
                s+=nums[j];
            }
            else{
                s+=nums[j];
                ans=max(ans,s);
                s=0;
            }
            j++;
        }
        s+=nums[nums.size()-1];
        ans=max(ans,s);
        return ans;
    }
};