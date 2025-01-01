class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        map<int,vector<pair<int,int>>>adj;
        int maxi = INT_MIN;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int>vec(n+1,INT_MAX);
        queue<int>q;
        int cnt=0;
        q.push(k);
        vec[k]=0;
        while(!q.empty()){
            for(int i=0;i<vec.size();i++){
            // maxi = max(maxi,vec[i]);
            cout<<vec[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<adj[q.front()].size();i++){
                if(vec[adj[q.front()][i].first]>vec[q.front()]+adj[q.front()][i].second){
                    vec[adj[q.front()][i].first] = vec[q.front()]+adj[q.front()][i].second;
                    q.push(adj[q.front()][i].first);
                }
            }
            q.pop();
        }
        for(int i=1;i<vec.size();i++){
            maxi = max(maxi,vec[i]);
        }
        return maxi==INT_MAX ? -1:maxi;
    }
};