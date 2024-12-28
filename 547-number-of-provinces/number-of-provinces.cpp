class Solution {
public:
    void solve(map<int,int>& visited,int val,map<int,vector<int>>adj){
        visited[val]=1;
        for(int i=0;i<adj[val].size();i++){
            if(visited[adj[val][i]]==0){
                solve(visited,adj[val][i],adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        map<int,vector<int>>adj;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        map<int,int>visited;
        for(int i=0;i<isConnected[0].size();i++){
            if(visited[i]==0){
                cnt++;
                solve(visited,i,adj);
            }
        }
        return cnt;
    }
};