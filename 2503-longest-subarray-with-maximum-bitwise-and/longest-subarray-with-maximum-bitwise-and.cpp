class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0,cnt = 0,ans = 1;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] == maxi){
                cnt+=1;
            }
            else{
                ans = max(ans,cnt);
                cnt=0;
            }
        }
        ans = max(ans,cnt);
        return ans;
    }
};