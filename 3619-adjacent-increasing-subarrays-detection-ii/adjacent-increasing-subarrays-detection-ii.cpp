class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        // 1 2 3 4 5 1 2 3 1 1
        // 5 4 3 2 1 3 2 1 1 1 
        vector<int>left;
        vector<int>right;
        int val=1,ans=0;
        left.push_back(1);
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i])val++;
            else val=1;
            left.push_back(val);
        }
        val=1;
        right.push_back(1);
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1])val++;
            else val = 1;
            right.push_back(val);
        }
        reverse(right.begin(),right.end());
        // for(int i=0;i<right.size();i++){
        //     cout<<right[i]<<" ";
        // }
        for(int i=0;i<left.size()-1;i++){
            ans = max(ans,min(left[i],right[i+1]));
        }
        return ans;
    }
};