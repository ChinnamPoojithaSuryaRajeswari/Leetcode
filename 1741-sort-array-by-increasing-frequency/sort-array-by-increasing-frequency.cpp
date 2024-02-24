class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]!=0){
                mp[nums[i]]+=1;
            }
            else{
                mp[nums[i]]=1;
            }
        }
        map<int,vector<int>>ans;
        for(auto it:mp){
            ans[it.second].push_back(it.first);
        }
        for(auto it:ans){
            sort(it.second.begin(),it.second.end());
        }
        vector<int>res;
        for(auto it:ans){
            reverse(it.second.begin(),it.second.end());
            for(int j=0;j<it.second.size();j++){
                for(int i=0;i<it.first;i++){
                    // cout<<it.second[i]<<" ";/
                    res.push_back(it.second[j]);
                }
            }
        }
        return res;
    }
};