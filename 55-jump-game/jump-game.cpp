class Solution {
public:
    bool canJump(vector<int>& nums) {
        //  int index,value=0,i=0,j;
        // while(i<nums.size()-1){
        //     index = 0;
        //     value=0;
        //     if(i+nums[i]>=nums.size()-1){
        //         return true;
        //     }
        //     else{
        //         for(j=i;j<=i+nums[i];j++){
        //             if(value<=nums[j]){
        //                 value = nums[j];
        //                 index = j;
        //             }
        //         }
        //         if(i+nums[i]>i+index-i){
        //             i+=nums[i];
        //         }
        //         else{
        //             i=i+index-i;
        //         }
        //         if(i>=nums.size()-1){
        //             return true;
        //         }
        //         if(nums[i]==0 and i!=nums.size()-1){
        //             return false;
        //         }
        //         else if(nums[i]==0){
        //             return true;
        //         }
        //     }
        // }
        // return true;
        int ans=0;
        for (int i=0;i<nums.size();i++){
            if (ans<i){
                return false;
            }
            ans=max(ans,i+nums[i]);
        }
        return true;
    }
};