class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int>dist1(edges.size(),INT_MAX);
        vector<int>dist2(edges.size(),INT_MAX);
        dist1[node1]=0;
        queue<int>q;
        q.push(node1);
        while(!q.empty()){
            int t=q.front();
            if(edges[t]!=-1 && dist1[edges[t]]==INT_MAX){
                dist1[edges[t]]=min(dist1[edges[t]],dist1[t]+1);
                q.push(edges[t]);
            }
            q.pop();
        }
        dist2[node2]=0;
        q.push(node2);
        while(!q.empty()){
            int t=q.front();
            if(edges[t]!=-1 && dist2[edges[t]]==INT_MAX){
                dist2[edges[t]]=min(dist2[edges[t]],dist2[t]+1);
                q.push(edges[t]);
            }
            q.pop();
        }
        int ans=INT_MAX,ind=-1;
        for(int i = 0;i < dist1.size();i++){
            if(max(dist1[i],dist2[i])<ans){
                ind=i;
                ans=max(dist1[i],dist2[i]);
            }
        }
        return ind;
    }
};