class Solution {
public:
    void rec(vector<int>nums,vector<int>vec,vector<vector<int>>&ans,int index){
        if(index == nums.size()){
            ans.push_back(vec);
            return;
        }
        vec.push_back(nums[index]);
        rec(nums,vec,ans,index+1);
        vec.erase(vec.begin()+vec.size()-1);
        rec(nums,vec,ans,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>vec;
        vector<vector<int>>ans;
        rec(nums,vec,ans,0);
        return ans;
    }
};