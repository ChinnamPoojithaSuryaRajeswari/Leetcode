class Solution {
public:
    void rec(vector<int>nums,vector<int>vec,vector<vector<int>>&ans,int index,int sum,int target,int k){
        if(index == nums.size()){
            if(sum==target and vec.size()==k){
                ans.push_back(vec);
            }
            return;
        }
        vec.push_back(nums[index]);
        sum+=nums[index];
        rec(nums,vec,ans,index+1,sum,target,k); 
        sum-=vec[vec.size()-1];
        vec.erase(vec.begin()+vec.size()-1);
        rec(nums,vec,ans,index+1,sum,target,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>vec;
        vector<vector<int>>ans;
        vector<int>nums;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        rec(nums,vec,ans,0,0,n,k);
        return ans;
    }
};