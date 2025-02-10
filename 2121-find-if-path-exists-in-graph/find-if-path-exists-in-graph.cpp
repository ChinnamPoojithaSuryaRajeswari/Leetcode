class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         vector<vector<int>>adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        vector<int>visited(n,0);
        visited[source] = 1;
        q.push(source);
        while(!q.empty()){
            int topOfQueue = q.front();
            if(topOfQueue==destination) return true;
            q.pop();
            for(int i = 0 ; i < adj[topOfQueue].size() ; i++){
                if(visited[adj[topOfQueue][i]] == 0){
                    q.push(adj[topOfQueue][i]);
                    visited[adj[topOfQueue][i]] = 1;
                }
            }
        }
        return false;
    }
};