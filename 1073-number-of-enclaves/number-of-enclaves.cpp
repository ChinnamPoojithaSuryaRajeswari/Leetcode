class Solution {
public:
    void bfs(vector<vector<int>>& grid,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int  m=q.front().first,p=q.front().second;
            grid[m][p]=0;
            if(m+1>=0 and m+1<grid.size() and grid[m+1][p]==1){
                grid[m+1][p]=0;
                q.push({m+1,p});
            }
            if(m-1>=0 and m-1<grid.size() and grid[m-1][p]==1){
                grid[m-1][p]=0;
                q.push({m-1,p});
            }
            if(p-1>=0 and p-1<grid[m].size() and grid[m][p-1]==1){
                grid[m][p-1]=0;
                q.push({m,p-1});
            }
            if(p+1>=0 and p+1<grid[m].size() and grid[m][p+1]==1){
                grid[m][p+1]=0;
                q.push({m,p+1});
            }
            q.pop();
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1){
                bfs(grid,i,0);
            }
            if(grid[i][grid[i].size()-1]==1){
                bfs(grid,i,grid[i].size()-1);
            }
        }
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]==1){
                bfs(grid,0,i);
            }
            if(grid[grid.size()-1][i]==1){
                bfs(grid,grid.size()-1,i);
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};