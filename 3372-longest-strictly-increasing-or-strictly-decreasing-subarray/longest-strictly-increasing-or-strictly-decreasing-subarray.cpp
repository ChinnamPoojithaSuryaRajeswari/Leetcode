class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt=0,ans=0,j=0;
        while(j+1<nums.size()){
            if(nums[j]<nums[j+1]){
                cnt++;
            }
            else{
                ans=max(ans,cnt);
                cnt=0;
            }
            j++;
        }
        ans=max(ans,cnt);
        j=0;
        cnt=0;
        while(j+1<nums.size()){
            if(nums[j]>nums[j+1]){
                cnt++;
            }
            else{
                ans=max(ans,cnt);
                cnt=0;
            }
            j++;
        }
        ans=max(ans,cnt);
        return ans+1;
    }
};