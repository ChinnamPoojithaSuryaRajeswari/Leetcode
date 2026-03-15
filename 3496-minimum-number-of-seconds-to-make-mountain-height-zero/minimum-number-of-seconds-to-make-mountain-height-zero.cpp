class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        vector<int>v(n,1);
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            pq.push({workerTimes[i],i});
        }
        while(mountainHeight > 0){
            long long a = pq.top()[0], b = pq.top()[1];
            pq.pop();
            ans = max(ans,a);
            v[b]+=1;
            long long t = workerTimes[b];
            a+=(t*v[b]);
            pq.push({a,b});
            mountainHeight -= 1;
        }
        return ans;
    }
};