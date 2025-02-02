class Solution {
public:
    bool check(vector<int>& nums) {
        int c=0,mx=INT_MIN,mi=INT_MAX;
        if(nums.size()==1) return true;
        for(int i=0;i<nums.size()-1;i++){
            if(c==1){
                if(nums[i]>mx or nums[i]>mi){
                    return false;
                }
                if(nums[i]>nums[i+1]){
                    return false;
                }
            }
            else{
                if(nums[i]>nums[i+1]){
                    c=1;
                }
                mx=max(mx,nums[i]);
                mi=min(mi,nums[i]);
            }
        }
        if(c==1 && (nums[nums.size()-1]>mx or nums[nums.size()-1]>mi)){
            return false;
        }
        return true;
    }
};