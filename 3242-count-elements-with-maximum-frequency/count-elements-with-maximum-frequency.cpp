class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mpp;
        int p=0,ans=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]+=1;
            if(mpp[nums[i]]>p){
                p=mpp[nums[i]];
            }
        }
        // cout<<p;
        for(auto it:mpp){
            if(it.second == p){
                ans+=p;
            }
        }
        return ans;
    }
};