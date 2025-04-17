class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(mpp[k-nums[i]]){
                mpp[k-nums[i]]--;
                ans+=1;
            }
            else{
                mpp[nums[i]]+=1;
            }
        }
        return ans;
    }
};