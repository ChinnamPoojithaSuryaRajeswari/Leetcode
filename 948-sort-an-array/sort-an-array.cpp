class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int>pq;
        vector<int>vec;
        for(int i=0;i<nums.size();i++){
            pq.push((-1)*nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            vec.push_back((-1)*pq.top());
            pq.pop();
        }
        return vec;
    }
};