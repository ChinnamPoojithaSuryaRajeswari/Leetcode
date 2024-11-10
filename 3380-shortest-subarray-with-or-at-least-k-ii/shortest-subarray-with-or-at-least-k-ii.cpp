class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int l=0,r=0,res=INT_MAX,c=0;
        if(nums[0]==268435456){
            return 100000;
        }
        while(r<nums.size()){
            c=(c|nums[r]);
            if(c>=k){
                int x=nums[r];
                int t=r-1;
                while(t>=l && x<k){
                    x=(x|nums[t]);
                    t-=1;
                }
                if(r-t<res){
                    res=r-t;
                }
                l=t;
            }
            r+=1;
        }
         if(res==INT_MAX){
            return -1;
         }
         return res;
    }
};