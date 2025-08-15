class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        queue<pair<int,vector<int>>>q;
        q.push({0,{0}});
        while(!q.empty()){
            int tp = q.front().first;
            vector<int> res = q.front().second;
            q.pop();
            for(int i=0;i<graph[tp].size();i++){
                res.push_back(graph[tp][i]);
                if(graph[tp][i]==graph.size()-1)ans.push_back(res);
                q.push({graph[tp][i],res});
                res.pop_back();
            }
        }
        return ans;
    }
};