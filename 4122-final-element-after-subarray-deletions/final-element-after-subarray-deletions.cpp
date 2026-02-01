class Solution {
public:
    int finalElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int i=0,j=nums.size()-1,flag=1;
        // while(i<j){
        //     if(flag){
        //         i++;
        //         flag = !flag;
        //     }
        //     else{
        //         j--;
        //         flag = !flag;
        //     }
        // }
        // return nums[i];
        return max(nums[0], nums[nums.size() - 1]);
    }
};