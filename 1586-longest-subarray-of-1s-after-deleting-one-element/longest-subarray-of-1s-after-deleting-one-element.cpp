class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>prefix;
        prefix.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            prefix.push_back(nums[i]+prefix[i-1]);
        }
        int prev=0,prevIndex=-1,ans=0,flag=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(prevIndex==-1){
                    ans = max(ans,prefix[i]);
                    prev = prefix[i];
                    prevIndex=i-1;
                    flag=1;
                }
                else{
                    ans = max(ans,prefix[i]-prefix[prevIndex]+prev);
                    prev = prefix[i]-prefix[prevIndex];
                    prevIndex=i-1;
                }
            }
        }
        if(nums[nums.size()-1]==1){
            if(prevIndex==-1 and flag!=1){
                ans = prefix[nums.size()-1]-1;
            }
            else{
                if(prevIndex==-1)prevIndex=0;
                ans = max(ans,prefix[nums.size()-1]-prefix[prevIndex]+prev);
                prev = prefix[nums.size()-1]-prefix[prevIndex];
            }
        }
        return ans;
    }
};