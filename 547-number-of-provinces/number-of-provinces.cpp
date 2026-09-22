class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>adj(isConnected.size(),0);
        int flag=0;
        for(int i=0;i<isConnected.size();i++){
            flag++;
            queue<int>q;
            if(adj[i]==0)q.push(i);
            while(!q.empty()){
                for(int j=0;j<isConnected[q.front()].size();j++){
                    if(adj[j]==0 and isConnected[q.front()][j]!=0){
                        q.push(j);
                        adj[j] = flag;
                    }
                }
                q.pop();
            }
        }
        set<int>st;
        for(int i=0;i<adj.size();i++){
            st.insert(adj[i]);
        }
        int val = 0;
        for(int i=0;i<adj.size();i++)if(adj[i]==0)val++;
        for(auto it:st)val++;
        return val;
    }
};