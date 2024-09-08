class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long prefixSum=0,s=0;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
        }
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            s+=nums[i];
            if(s >= prefixSum-s){
                cnt+=1;
            }
        }
        return cnt;
    }
};