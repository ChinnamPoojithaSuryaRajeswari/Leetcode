class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0,cnt=0;
        while(j<nums.size()){
            if(nums[j]-nums[i]<=k){
                j++;
            }
            else{
                i=j;
                j++;
                cnt++;
            }
        }
        cnt++;
        return cnt;
    }
};