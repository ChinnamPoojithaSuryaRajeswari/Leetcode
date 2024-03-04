class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long>pq;
        for(int i=0;i<nums.size();i++){
            nums[i]*=(-1);
            pq.push(nums[i]);
        }
        int count=0;
        long long int y;
        if((-1)*pq.top()>=k){
            return 0;
        }
        while((-1)*pq.top()<k){
            long q = pq.top();
            pq.pop();
            q=(-1)*q;
            long p = pq.top();
            pq.pop();
            p=(-1)*p;
            long w = min(p,q);
           long z = max(p,q);
            long e = 1e9+7;
           long y = ((2*w))+(z);
            y=(-1)*y;
            pq.push(y);
            count+=1;
        }
        return count;
    }
};