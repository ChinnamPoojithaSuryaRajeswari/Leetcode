class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0,j=0,maxi=0,ans=1;
        if(nums.size()==1)return 0;
        while(i+nums[i]<nums.size()-1){
            int val = nums[i],index=-1;
            j = i;
            maxi=0;
            while(j<nums.size() and val+1){
                val--;
                if(j+nums[j] >= maxi){
                    maxi  = j+nums[j];
                    index = j;
                }
                j++;
            }
            i = index;
            ans++;
        }
        return ans;
    }
};