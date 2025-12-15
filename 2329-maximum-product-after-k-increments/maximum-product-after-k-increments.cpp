class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int>pq;
        long long ans = 1, e = 1e9+7;
        for(int i=0;i<nums.size();i++){
            pq.push((-1)*nums[i]);
        }
        while(k){
            int tp = (-1)*pq.top();
            pq.pop();
            k--;
            pq.push((-1)*(tp+1));
        }
        while(!pq.empty()){
            int tp = (-1)*pq.top();
            pq.pop();
            ans = ((ans%e)*(tp%e))%e;
        }
        return ans;
    }
};