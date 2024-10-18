class Solution {
public:
    void rec(vector<int>nums,int index,int& maxi,int& cnt,int s){
        if(index>=nums.size()){
            if(s>maxi){
                cnt=1;
                maxi = s;
            }
            else if(s==maxi){
                cnt+=1;
            }
            return;
        }
        rec(nums,index+1,maxi,cnt,s);
        s=s|nums[index];
        rec(nums,index+1,maxi,cnt,s);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int index=0,maxi=0,cnt=0,s=0;
        rec(nums,index,maxi,cnt,s);
        return cnt;
    }
};