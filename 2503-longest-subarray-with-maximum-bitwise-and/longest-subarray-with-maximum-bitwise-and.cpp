class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max=nums[0];
        for(int i=0;i<nums.size();i++){
            if(max<nums[i]){
                max=nums[i];
            }
        }
        int i=0,c=0,res=1;
        while(i<nums.size()){
            if(nums[i]==max){
                c+=1;
            }
            else{
                if(c>res){
                    res=c;
                }
                c=0;
            }
            i+=1;
        }
        if(c>res){
            res=c;
        }
        return res;
    }
};