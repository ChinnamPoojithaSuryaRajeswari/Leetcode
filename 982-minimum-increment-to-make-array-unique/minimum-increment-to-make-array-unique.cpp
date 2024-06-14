class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int,int>mpp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]+=1;
        }
        int k,c=0;
        auto it = mpp.begin();
        while(it!=mpp.end()){
            k=0;
            if(it->second>1){
                k=it->second-1;
                it->second=1;
                c+=k;
                mpp[it->first+1]+=k;
            }
            it++;
        }
        it--;
        if(it->second>1){
            k=it->second-1;
            c+=(k*(k-1))/2;
        }
        return c;
    }
};