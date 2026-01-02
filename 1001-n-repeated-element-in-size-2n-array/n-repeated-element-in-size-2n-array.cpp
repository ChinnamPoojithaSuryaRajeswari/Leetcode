class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int>res(100000,0);
        for(int i=0;i<nums.size();i++){
            if(res[nums[i]]!=0)return nums[i];
            res[nums[i]]=1;
        }
        return -1;
    }
};