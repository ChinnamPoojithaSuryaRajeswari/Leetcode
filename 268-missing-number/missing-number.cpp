class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s=s^nums[i]^i;
        }
        s=s^nums.size();
        return s;
    }
};