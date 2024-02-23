class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int>prefix;
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            prefix.push_back(s);
        }
        int count=0;
        map<int,int>mp;
        for(int i=0;i<prefix.size();i++){
            if(prefix[i]==goal){
                count+=1;
                if(mp[prefix[i]-goal]!=0){
                    count+=mp[prefix[i]-goal];
                }
                if(mp[prefix[i]]==0){
                    mp[prefix[i]]=1;
                }
                else{
                    mp[prefix[i]]+=1;
                }
            }
            else{
                if(mp[prefix[i]-goal]!=0){
                    count+=mp[prefix[i]-goal];
                }
                if(mp[prefix[i]]==0){
                    mp[prefix[i]]=1;
                }
                else{
                    mp[prefix[i]]+=1;
                }
            }
        }
        return count;
    }
};