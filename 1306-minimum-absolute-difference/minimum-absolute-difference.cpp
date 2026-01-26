class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=0,mini=INT_MAX;
        while(j<nums.size()-1){
            mini = min(mini,nums[j+1]-nums[j]);
            j++;
        }
        j=0;
        vector<vector<int>>ans;
        while(j<nums.size()-1){
            if(mini==nums[j+1]-nums[j]){
                ans.push_back({nums[j],nums[j+1]});
            }
            j++;
        }
        return ans;
    }
};