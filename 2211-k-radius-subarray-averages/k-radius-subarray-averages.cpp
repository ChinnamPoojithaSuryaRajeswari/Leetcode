class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long i=0,s=0,j;
        vector<int>vec;
        if(k==0){
            return nums;
        }
        if(k+1+k>nums.size()){
            vector<int>ans(nums.size(),-1);
            return ans;
        }
        for(i=0;i<k+1+k;i++){
            if(i<k){
            vec.push_back(-1);
            }
            s+=nums[i];
        }
        i=k;
        while(i+k<nums.size()){
           vec.push_back(s/(k+k+1));
            s-=nums[i-k];
            i+=1;
            if(i+k<nums.size()){
                s+=nums[i+k];
            }
        }
        while(i<nums.size()){
            vec.push_back(-1);
            i+=1;
        }
        return vec;
    }
};