class Solution {
public:
    void call(vector<int> &nums,int i,set<vector<int>>& st,vector<int> nu){
        if(i >= nums.size()){
            sort(nu.begin(),nu.end());
            st.insert(nu);
            return;
        }
        nu.push_back(nums[i]);
        call(nums,i+1,st,nu);
        nu.pop_back();
        call(nums,i+1,st,nu);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>nu;
        set<vector<int>>st;
        call(nums,0,st,nu);
        vector<vector<int>>ans;
        for(auto it:st)ans.push_back(it);
        return ans;
    }
};