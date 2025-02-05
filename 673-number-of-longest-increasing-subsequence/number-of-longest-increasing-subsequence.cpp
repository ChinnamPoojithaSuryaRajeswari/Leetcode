class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>>dpleft(nums.size(),{0,0});
        int maxlen = 0 ,cnt = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j>=0;j--){
                if(nums[i] > nums[j]){
                    dpleft[i].first = max(dpleft[i].first,dpleft[j].first+1);
                }
            }
            for(int j=i;j>=0;j--){
                if(nums[i] > nums[j] && dpleft[j].first==dpleft[i].first-1){
                    dpleft[i].second +=dpleft[j].second; 
                }
            }
            dpleft[i].first = max(dpleft[i].first,1);
            if(dpleft[i].second==0)dpleft[i].second=1;
            if(dpleft[i].first > maxlen){
                maxlen = dpleft[i].first;
            }
        }
        for(int i=0;i<dpleft.size();i++){
            cout<<dpleft[i].first<<" "<<dpleft[i].second<<endl;
            if(dpleft[i].first == maxlen)cnt+=dpleft[i].second;
        }
        return cnt;
    }
};