class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>largest;
        vector<int>smallest;
        int maxxy = nums[0], minni = nums[nums.size()-1];
        for(int i=0;i<nums.size();i++){
            maxxy = max(maxxy,nums[i]);
            largest.push_back(maxxy);
            cout<<maxxy<<" ";
        }
        for(int i=nums.size()-1;i>=0;i--){
            minni = min(minni,nums[i]);
            smallest.push_back(minni);
            cout<<minni<<" ";
        }
        reverse(smallest.begin(),smallest.end());
        for(int i=0;i<nums.size();i++){
            if(largest[i] - smallest[i]<=k)return i;
        }
        return -1;
    }
};