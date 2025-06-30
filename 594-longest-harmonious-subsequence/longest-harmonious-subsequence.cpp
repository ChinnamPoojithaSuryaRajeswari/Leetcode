class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]+=1;
        }
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]+1]!=0){
                ans=max(ans,mpp[nums[i]+1]+mpp[nums[i]]);
            }
        }
        return ans;
    }
};