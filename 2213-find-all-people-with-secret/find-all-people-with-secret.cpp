class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> visited(n, 0);
        vector<int> time(n, INT_MAX);
        for (auto &m : meetings) {
            adj[m[0]].push_back({m[1], m[2]});
            adj[m[1]].push_back({m[0], m[2]});
        }
        time[0] = 0;
        time[firstPerson] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
        q.push({0, 0});
        q.push({0, firstPerson});
        while (!q.empty()) {
            int t = q.top().first;
            int tp = q.top().second;
            q.pop();
            if (t > time[tp]) continue;
            for (auto &it : adj[tp]) {
                int nxt = it.first;
                int meetTime = it.second;
                if (meetTime >= t && meetTime < time[nxt]) {
                    time[nxt] = meetTime;
                    q.push({meetTime, nxt});
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (time[i] != INT_MAX)
                ans.push_back(i);
        }
        return ans;
    }
};