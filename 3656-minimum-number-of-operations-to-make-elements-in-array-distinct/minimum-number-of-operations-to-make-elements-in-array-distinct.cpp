class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        map<int,int>mpp;
        int i;
        for(i=nums.size()-1;i>=0;i--){
            mpp[nums[i]]+=1;
            if(mpp[nums[i]]==2){
                break;
            }
        }
        if((i+1)%3==0){
            return (i+1)/3;
        }
        return ((i+1)/3)+1;
    }
};