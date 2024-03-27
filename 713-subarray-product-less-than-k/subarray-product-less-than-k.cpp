class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int c=0,s=1;
        for(int i=0;i<nums.size();i++){
            s=1;
            for(int j=i;j<nums.size();j++){
                s*=nums[j];
                if(s<k){
                    c+=1;
                }
                else{
                    break;
                }
            }
        }
        return c;
    }
};