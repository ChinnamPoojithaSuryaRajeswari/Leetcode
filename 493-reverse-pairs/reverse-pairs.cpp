class Solution {
public:
    void merge(vector<int>& nums,int l,int h,int &ans){
        vector<int>res;
        int mid = (l+h) / 2;
        for(int i=mid+1;i<=h;i++){
            long long req = nums[i];
            req=req*2;
            int low = l, high = mid, index = mid+1;
            while(low<=high){
                int  m = (low+high)/2;
                if(nums[m]>req){
                    index = m;
                    high = m-1;
                }
                else{
                    low = m+1;
                }
            }
            ans+=(mid+1-index);
        }
        int i=l,j=mid+1;
        while(i<=mid && j<=h) {
            if(nums[i]>nums[j]) res.push_back(nums[j++]);
            else{
                res.push_back(nums[i++]);
            }
        }
        while(i<=mid)res.push_back(nums[i++]);
        while(j<=h)res.push_back(nums[j++]);
        i=l;
        for(auto it:res)nums[i++]=it;
    }
    void divideAndConcure(vector<int>&nums,int l,int h,int &ans){
        if(l<h){
            int mid = (l+h) / 2;
            divideAndConcure(nums,l,mid,ans);
            divideAndConcure(nums,mid+1,h,ans);
            merge(nums,l,h,ans);
        }
        return;
    }
    int reversePairs(vector<int>& nums) {
        int ans=0;
        divideAndConcure(nums,0,nums.size()-1,ans);
        return ans;
    }
};