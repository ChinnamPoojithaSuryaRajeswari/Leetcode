class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int cnt = 0 , maxi = INT_MIN , j = 1;
        sort(nums.begin(),nums.end());
        while(j<nums.size()){
            if(nums[j]==nums[j-1]+1){
                cnt++;
            }
            else if(nums[j]==nums[j-1]){
                j++;
                continue;
            }
            else{
                maxi  = max(maxi,cnt);
                cnt = 0;
            }
            j++;
        }
        maxi  = max(maxi,cnt);
        return maxi+1;
    }
};