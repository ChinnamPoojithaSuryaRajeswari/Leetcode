class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>> adj(26);
        for(int i=0;i<s1.size();i++){
            adj[int(s1[i])-'a'].push_back(int(s2[i])-'a');
            adj[int(s2[i])-'a'].push_back(int(s1[i])-'a');
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++){
            int res = INT_MAX;
            vector<int>visited(26,0);
            if(adj[int(baseStr[i])-'a'].size()){
                queue<int>q;
                q.push(int(baseStr[i])-'a');
                visited[int(baseStr[i])-'a']=1;
                while(!q.empty()){
                    int tp = q.front();
                    res = min(res,tp);
                    q.pop();
                    for(int j=0;j<adj[tp].size();j++){
                        res = min(res,adj[tp][j]);
                        if(visited[adj[tp][j]]==0)q.push(adj[tp][j]);
                        visited[adj[tp][j]]=1;
                    }
                }
                ans+='a'+res;
            }
            else{
                ans+=baseStr[i];
            }
        }
        return ans;
    }
};