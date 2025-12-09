class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        map<int,int>mpp;
        map<int,int>mp;
        int ans=0,mod = 1e9+7;
        mp[nums[0]]+=1;
        for(int i=1;i<nums.size();i++)mpp[nums[i]]+=1;
        for(int i=1;i<nums.size();i++){
            mpp[nums[i]]--;
            if(mpp[nums[i]*2] and mp[nums[i]*2]){
                long long p = ( ( (long long)mpp[nums[i]*2] % mod ) * ( (long long)mp[nums[i]*2] % mod ) ) % mod;
        ans = (int)( ( ( (long long)ans % mod ) + p ) % mod );
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};