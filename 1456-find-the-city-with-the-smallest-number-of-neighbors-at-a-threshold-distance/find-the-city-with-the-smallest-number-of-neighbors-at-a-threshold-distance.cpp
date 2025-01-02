class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int ans = INT_MAX,val=-1;
        for(int i=0;i<n;i++){
            vector<int>vec(n,INT_MAX);
            queue<int>q;
            int cnt=0;
            q.push(i);
            vec[i]=0;
            while(!q.empty()){
                for(int i=0;i<adj[q.front()].size();i++){
                    if(vec[adj[q.front()][i].first]>vec[q.front()]+adj[q.front()][i].second){
                        vec[adj[q.front()][i].first] = vec[q.front()]+adj[q.front()][i].second;
                        q.push(adj[q.front()][i].first);
                    }
                }
                q.pop();
            }
            for(int j=0;j<vec.size();j++){
                if(vec[j]<=distanceThreshold)cnt++;
            }
            if(cnt <= ans){
                val = i;
                ans=cnt;
            }
        }
        return val;
    }
};