class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int i=0,j=0,maxi=INT_MIN;
        sort(nums.begin(),nums.end());
        while(j<nums.size()){
            if(nums[j]-nums[i]>2*k){
                i++;
                maxi = max(maxi,j-i+1);
            }
            else{
                j++;
            }
        }
        maxi = max(maxi,j-i);
        return maxi;
    }
};