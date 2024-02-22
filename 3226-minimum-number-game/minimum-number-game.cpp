class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int>prirty;
        for(int i=0;i<nums.size();i++){
            prirty.push((-1)*nums[i]);
        }
        vector<int>ans;
        while(!prirty.empty()){
            int p=prirty.top();
            prirty.pop();
            ans.push_back((-1)*prirty.top());
            ans.push_back((-1)*p);
            prirty.pop();
        }
        return ans;
    }
};