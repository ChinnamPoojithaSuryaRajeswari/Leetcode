class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int answer=0,i=0,j=0,ans=0;
        map<int,int>mpp;
        while(j<nums.size()){
            mpp[nums[j]]++;
            answer+=nums[j];
            if(mpp[nums[j]]>1){
                while(i<nums.size()){
                    mpp[nums[i]]--;
                    answer-=nums[i];
                    if(mpp[nums[i]]==1){
                        i++;
                        break;
                    }
                    i++;
                }
            }
            j++;
            ans = max(ans,answer);
        }
        return ans;
    }
};