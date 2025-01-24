class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>outdegree(graph.size(),0);
        map<int,vector<int>>mpp;
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            outdegree[i]=graph[i].size();
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                mpp[graph[i][j]].push_back(i);
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            for(int i=0;i<mpp[q.front()].size();i++){
                outdegree[mpp[q.front()][i]]--;
                if(outdegree[mpp[q.front()][i]]==0){
                    q.push(mpp[q.front()][i]);
                }
            }
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};