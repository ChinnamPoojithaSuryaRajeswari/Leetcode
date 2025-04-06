class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<pair<int,int>>dp(nums.size(),{-1,1});
        int maxi = 0;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(dp[i].second <= dp[j].second+1){
                        dp[i].first = j;
                        dp[i].second = dp[j].second+1;
                        maxi = max(maxi,dp[i].second);
                    }
                }
            }
        }
        if(maxi == 1)return {nums[0]};
        int k = 0;
        for(int i=dp.size()-1;i>=0;i--){
            if(dp[i].second == maxi){
                k = i;
                break;
            }
        }
        vector<int>answer;
        while(k>=0){
            answer.push_back(nums[k]);
            k = dp[k].first;
        }
        return answer;
    }
};