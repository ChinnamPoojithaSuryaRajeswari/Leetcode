class Solution {
public:
    void rec(vector<int>&nums,int index,int xr,int& sm){
        if(index>=nums.size()){
            sm+=xr;
            return;
        }
        rec(nums,index+1,xr^nums[index],sm);
        rec(nums,index+1,xr,sm);
    }
    int subsetXORSum(vector<int>& nums) {
        int sm=0,xr=0;
        rec(nums,0,xr,sm);
        return sm;
    }
};