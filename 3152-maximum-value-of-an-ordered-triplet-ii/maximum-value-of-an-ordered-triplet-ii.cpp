class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int>prefix_Max;
        vector<int>sufix_Max;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi = max(nums[i],maxi);
            prefix_Max.push_back(maxi);
        }
        maxi = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            maxi = max(nums[i],maxi);
            sufix_Max.push_back(maxi);
        }
        reverse(sufix_Max.begin(),sufix_Max.end());
        long long ans = 0;
        for(int i=0;i<nums.size()-1;i++){
            long long a = prefix_Max[i]-nums[i];
            long long b = a*sufix_Max[i+1];
            ans = max(ans,b);
            cout<<i<<" "<<ans<<" ";
        }
        return ans;
    }
};