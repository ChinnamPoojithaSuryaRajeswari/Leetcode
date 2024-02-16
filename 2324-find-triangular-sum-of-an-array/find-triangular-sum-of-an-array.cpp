class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()>1){
            int i=0;
            while(i+1<nums.size()){
                nums[i]=(nums[i]+nums[i+1])%10;
                i+=1;
            }
            nums.erase(nums.begin()+nums.size()-1);
        }
        return nums[0];
    }
};