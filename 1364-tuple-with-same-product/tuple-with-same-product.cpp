class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                mp[nums[i]*nums[j]]+=1;
            }
        }
        long long c=0;
        for(auto i:mp){
            if(i.second>=2){
                int x=i.second-1;
                long long y=(x*(x+1))/2;
                c+=(y*8);
            }
        }
        return c;
    }
};