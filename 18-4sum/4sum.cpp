class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        set<vector<int>> mp;
        sort(nums.begin(),nums.end());
        if(nums.size()<4){
            return answer;
        }
        for(int i = 0; i < nums.size()-3; i++) {
            for(int j = i + 1; j < nums.size()-2; j++) {
                // cout<<res<<" ";
                long long x=  target-nums[i];
                long long res=x-nums[j];
                cout<<res<<endl;
                int k=j+1,l=nums.size()-1;
                while(k<l) {
                    long long y=nums[k]+nums[l];
                    if(y==res) {
                        mp.insert({nums[i],nums[j],nums[k],nums[l]}); 
                        k+=1;
                        l-=1;
                    }
                    else if(y>res){
                        l-=1;
                    }
                    else{
                        k+=1;
                    }
                }
            }
        }
        for(auto it : mp) {
            answer.push_back(it);
        }
        return answer;
    }
};