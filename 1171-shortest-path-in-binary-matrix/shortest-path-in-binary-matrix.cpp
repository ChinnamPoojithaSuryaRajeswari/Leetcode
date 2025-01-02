class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>visited(grid.size(),(vector<int>(grid[0].size(),0)));
        queue<pair<pair<int,int>,int>>q;
        int ans=INT_MAX;
        if(grid[0][0]==1) return -1;
        int cnt=0;
        q.push({{0,0},cnt});
        visited[0][0]=1;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            if(i+1<grid.size() and j+1< grid.size() and visited[i+1][j+1]==0 and grid[i+1][j+1]==0){
                q.push({{i+1,j+1},q.front().second+1});
                visited[i+1][j+1]=1;
            }
            if(i-1>=0 and j-1>=0 and visited[i-1][j-1]==0 and grid[i-1][j-1]==0){
                q.push({{i-1,j-1},q.front().second+1});
                visited[i-1][j-1]=1;
            }
            if(i-1>=0 and j+1<grid.size() and visited[i-1][j+1]==0 and grid[i-1][j+1]==0){
                q.push({{i-1,j+1},q.front().second+1});
                visited[i-1][j+1]=1;
            }
            if(i+1<grid.size() and j-1>=0 and visited[i+1][j-1]==0 and grid[i+1][j-1]==0){
                q.push({{i+1,j-1},q.front().second+1});
                visited[i+1][j-1]=1;
            }
            if(i+1<grid.size() and visited[i+1][j]==0 and grid[i+1][j]==0){
                q.push({{i+1,j},q.front().second+1});
                visited[i+1][j]=1;
            }
            if(i-1>=0 and visited[i-1][j]==0 and grid[i-1][j]==0){
                q.push({{i-1,j},q.front().second+1});
                visited[i-1][j]=1;
            }
            if(j+1<grid.size() and visited[i][j+1]==0 and grid[i][j+1]==0){
                q.push({{i,j+1},q.front().second+1});
                visited[i][j+1]=1;
            }
            if(j-1>=0 and visited[i][j-1]==0 and grid[i][j-1]==0){
                q.push({{i,j-1},q.front().second+1});
                visited[i][j-1]=1;
            }
            if(i==grid.size()-1 and j==grid.size()-1){
                ans=min(ans,q.front().second);
            }
            q.pop();
        }
        return ans==INT_MAX ? -1:ans+1;
    }
};

