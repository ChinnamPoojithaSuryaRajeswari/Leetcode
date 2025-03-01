class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisties) {
        map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(int i=0;i<prerequisties.size();i++){
            adj[prerequisties[i][0]].push_back(prerequisties[i][1]);
            indegree[prerequisties[i][1]]++;
        }
        queue<int>q;
        vector<int>visited(numCourses,0);
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                visited[i]=1;
                q.push(i);
            }
        }
        for(auto i:adj){

        }
        while(!q.empty()){
            int val = q.front();
            q.pop();
            for(int i=0;i<adj[val].size();i++){
                indegree[adj[val][i]]--;
                if(visited[adj[val][i]]==0){
                    if(indegree[adj[val][i]]==0){
                        q.push(adj[val][i]);
                        visited[adj[val][i]]=1;
                    }
                }
            }
        }
        for(int i = 0 ; i < indegree.size() ; i++){
            if(indegree[i]>=1)return false;
        }
        return true;
    }
};