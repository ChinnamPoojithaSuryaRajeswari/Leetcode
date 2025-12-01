class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        // map<int,int>mpp;
        // for(int i=0;i<nums.size();i++){
        //     mpp[nums[i]]=i+1;
        //     if(mpp[abs(nums[i] + valueDifference)] and abs(mpp[abs(nums[i]+valueDifference)]-1-i) >= indexDifference){
        //         return {mpp[abs(nums[i] + valueDifference)]-1,i};
        //     }
        // }
        // return {-1,-1};
        vector<int> arr={-1,-1};
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(abs(i-j)>=indexDifference && abs(nums[i]-nums[j])>=valueDifference){
                    arr[0]=i;
                    arr[1]=j;
                }
            }
        }
        return arr;
    }
};