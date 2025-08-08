class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> vec(n + 1); 
        for(int i=0;i<times.size();i++){
            vec[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>visited(n+1,INT_MAX);
        queue<pair<int,int>>q;
        q.push({k,0});
        visited[k] = 0;
        while(!q.empty()){
            int curr = q.front().first;
            int len = q.front().second;
            q.pop();
            for(int i=0;i<vec[curr].size();i++){
                if(visited[vec[curr][i].first] > len+vec[curr][i].second){
                    visited[vec[curr][i].first] = len+vec[curr][i].second;
                    q.push({vec[curr][i].first,len+vec[curr][i].second});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<n+1;i++){
            ans = max(ans,visited[i]);
        }
        return ans==INT_MAX ? -1:ans;
    }
};