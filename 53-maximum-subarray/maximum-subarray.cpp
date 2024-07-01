class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=nums[0];
        int i=0,s=0;
        while(i<nums.size()){
            s+=nums[i];
            if(s>=maxi){
                maxi=s;
            }
            if(s<0){
                s=0;
            }
            i+=1;
        }
        return maxi;
    }
};