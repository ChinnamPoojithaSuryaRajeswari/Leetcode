class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        // vector<int>ans(nums.size(),0);
        // for(int i=0;i<nums.size();i++){
        //     ans[i] = nums[((i + nums[i]) % nums.size() + nums.size()) % nums.size()];
        // }
        // return ans;
        int n = nums.size();
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            int targetidx = ((i + nums[i]) % n + n) % n;
            result[i] = nums[targetidx];
        }
        return result;
    }
};