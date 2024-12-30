class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>vec(graph.size(),-1);
        queue<int>q;
        int cnt=0;
        map<int,int>left;
        map<int,int>right;
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()!=0){
                cnt++;
            }
        }
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()!=0){
                if(vec[i]==-1){
                    // cout<<i<<" ";
                    q.push(i);
                    left[i]=1;
                    while(!q.empty()){
                        vec[q.front()]=1;
                        for(int i=0;i<graph[q.front()].size();i++){
                            if(left[q.front()]==1){
                                if(left[graph[q.front()][i]]){
                                    cout<<graph[q.front()][i]<<" ";
                                    return false;
                                }
                                right[graph[q.front()][i]]=1;
                            }
                            if(right[q.front()]==1){
                                if(right[graph[q.front()][i]]){
                                    return false;
                                }
                                left[graph[q.front()][i]]=1;
                            }
                            if(vec[graph[q.front()][i]]==-1){
                                q.push(graph[q.front()][i]);
                                vec[graph[q.front()][i]]=1;
                            }
                        }
                        q.pop();
                    }
                }
            }
        }
        return true;
    }
};