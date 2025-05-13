class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        vector<int>visited(numCourses,0);
        for(int i = 0 ; i < prerequisites.size() ; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]+=1;
        }
        queue<int>q;
        vector<int>ans;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i]==0){
                visited[i]=1;
                q.push(i);
            }
        }
        while(!q.empty()){
            int tp = q.front();
            ans.push_back(tp);
            q.pop();
            for(int i = 0 ; i < adj[tp].size() ; i++){
                indegree[adj[tp][i]]--;
                if(visited[adj[tp][i]]==0){
                    if(indegree[adj[tp][i]]==0){
                        q.push(adj[tp][i]);
                        visited[adj[tp][i]]=1;
                    }
                }
            }
        }
        for(int i = 0 ; i < numCourses ; i++){
            if(visited[i]==0)return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};