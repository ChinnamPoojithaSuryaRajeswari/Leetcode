class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>=nums.size())k=k%nums.size();
        vector<int>vec;
        int n = nums.size(),i=k;
        for(int i=nums.size()-k;i<nums.size();i++){
            vec.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()-k;i++)vec.push_back(nums[i]);
        nums.clear();
        nums=vec;
    }
};