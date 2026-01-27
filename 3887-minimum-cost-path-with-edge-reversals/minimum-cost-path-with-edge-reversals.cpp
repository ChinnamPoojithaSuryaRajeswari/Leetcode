class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],2*edges[i][2]});
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>visited(n,INT_MAX);
        while(!q.empty()){
            int weight = q.front().second;
            int val = q.front().first;
            // cout<<weight<<" ";
            for(int i=0;i<adj[val].size();i++){
                if(visited[adj[val][i].first] > weight+adj[val][i].second ){
                    q.push({adj[val][i].first,weight+adj[val][i].second});
                    visited[adj[val][i].first] = weight+adj[val][i].second;
                }
            }
            q.pop();
        }
        if(visited[n-1]==INT_MAX)return -1;
        return visited[n-1];
    }
};