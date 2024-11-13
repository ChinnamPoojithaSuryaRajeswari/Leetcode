class Solution {
public:
    int lowerBound(vector<int>&nums,int l,int h,int t){
        int ans=h+1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]>=t){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
    int upperBound(vector<int>&nums,int l,int h,int t){
        int ans=h+1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]>t){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long res=0;
        for(int i=0;i<nums.size()-1;i++){
            int x=lowerBound(nums,i+1,nums.size()-1,lower-nums[i]);
            int y=upperBound(nums,i+1,nums.size()-1,upper-nums[i]);
            res+=(y-x);
        }
        return res;
    }
};