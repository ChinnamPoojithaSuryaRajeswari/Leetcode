class Solution {
public:
    int jump(vector<int>& nums) {
       if(nums.size()==1)return 0;
        int ans=nums[0],c=0,index=0;
        for (int i=0;i<nums.size();i++){
            // int k = ans;
            ans=max(ans,i+nums[i]);//2
            if(index==i){//0==0
                index = ans;//2
                c+=1;
            }
            if(index>=nums.size()-1) return c;
        }
        //if(c==0) return 1;
        //if(index>=nums.size()-1) return c;
        return 0;
    }
};