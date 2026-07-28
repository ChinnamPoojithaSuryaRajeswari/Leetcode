class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int val1 = nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        int val2 = nums[nums.size()-1]*nums[1]*nums[0];
        return max(val1,val2);
    }
};