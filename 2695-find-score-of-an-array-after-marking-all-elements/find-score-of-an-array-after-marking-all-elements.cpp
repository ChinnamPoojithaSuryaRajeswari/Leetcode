class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long int ans = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        int i =0, n = nums.size();
        i = 0;
        while(i<n){
            pq.push({(-1)*nums[i],(-1)*i});
            i++;
        }
        vector<int> v(n,1);
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            if(v[(-1)*p.second]){
                ans += p.first;
                if((-1)*p.second-1>=0){
                    v[(-1)*p.second-1] = 0;
                }
                if((-1)*p.second+1<n){
                    v[(-1)*p.second+1] = 0;
                }
            }
        }
        return (-1)*ans;
    }
};