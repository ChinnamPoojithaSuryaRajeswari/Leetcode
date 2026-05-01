class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int answer = INT_MIN,res = 0,req = 0;
        for(int i=0;i<nums.size();i++){
            res += (i*nums[i]);
            req += nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            res = res+(req-nums[i])-((nums.size()-1)*nums[i]);
            answer = max(answer,res);
        }
        return answer;
    }
};