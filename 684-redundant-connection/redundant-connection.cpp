class Solution {
public:
    int find(int i,vector<int>&parent) {
        if (parent[i] == i) {
            return i;
        }
        return find(parent[i],parent);
    }
    void unite(int i, int j,vector<int>&parent) {
        int irep = find(i,parent);
        int jrep = find(j,parent);
        parent[irep] = jrep;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>parent;
        for(int i=0;i<edges.size()+1;i++)parent.push_back(i);
        for(int i=0;i<edges.size();i++){
            if((find(edges[i][0],parent) == find(edges[i][1],parent))){
                ans = {edges[i][0],edges[i][1]};
            }
            else{
                unite(edges[i][0],edges[i][1],parent);
            }
        }
        return ans;
    }
};