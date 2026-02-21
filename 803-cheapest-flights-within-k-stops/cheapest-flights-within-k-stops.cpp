class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(101);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int>visited(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;
        q.push({src,{0,0}});
        while(!q.empty()){
            int current= q.front().first;
            int price = q.front().second.first;
            int step = q.front().second.second;
            for(int i=0;i<adj[current].size();i++){
                int val = adj[current][i].first;
                int res = adj[current][i].second;
                if(val == dst){
                    if(step <= k){
                        if(visited[val] > price+res){
                            visited[val] = price+res;
                            q.push({val,{res+price,step+1}});
                        }
                    }
                }
                else{
                        if(step < k){
                            if(visited[val] > price+res){
                                visited[val] = price+res;
                                q.push({val,{res+price,step+1}});
                            }
                        }
                }
            }
            q.pop();
        }
        return visited[dst]==INT_MAX ? -1:visited[dst];
    }
};