class Solution {
public:
    int fun(vector<int> nums,int m){
        int res=0;
        for(int i=0;i<nums.size();i++){
            res+=(nums[i]/m);
            res+=(nums[i]%m ? 1:0);
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,h=*max_element(nums.begin(),nums.end()),mini=INT_MAX;
        while(l<=h){
            int m = (l+h)/2;
            int p = fun(nums,m);
            if(p<=threshold){
                h=m-1;
                mini = min(mini,m);
            }
            else{
                l=m+1;
            }
        }
        return mini==INT_MAX ? -1:mini;
    }
};