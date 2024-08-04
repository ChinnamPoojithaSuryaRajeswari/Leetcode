class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int s,ans = 0,e=1e9+7;
        vector<int> subarrySum;
        for(int i=0;i<nums.size();i++){
            s=0;
            for(int j=i;j<nums.size();j++){
                s=s+nums[j];
                s=s%e;
                subarrySum.push_back(s);
            }
        }
        sort(subarrySum.begin(),subarrySum.end());
        left-=1;
        right-=1;
        for(int i = left; i <= right; i++){
            if(i==subarrySum.size()){
                break;
            }
            ans = ((ans)%e + (subarrySum[i])%e)%e;
        }
        return ans%e;
    }
};