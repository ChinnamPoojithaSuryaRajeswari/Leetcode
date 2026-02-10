class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int even=0, odd= 0;
            map<int,int>mpp;
            for(int j=i;j<nums.size();j++){
                if(mpp[nums[j]]==0){
                    nums[j]%2==0 ? even++: odd++;
                }
                mpp[nums[j]]++;
                if(even==odd)ans=max(ans,(j-i+1));
            }
        }
        return ans;
    }
};