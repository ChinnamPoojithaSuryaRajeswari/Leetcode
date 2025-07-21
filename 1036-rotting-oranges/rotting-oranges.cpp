class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    grid[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int sze = q.size();
            while(sze--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i-1>=0){
                    if(grid[i-1][j]==1){
                        q.push({i-1,j});
                        grid[i-1][j]=0;
                    }
                }
                if(j-1>=0){
                    if(grid[i][j-1]==1){
                        q.push({i,j-1});
                        grid[i][j-1]=0;
                    }
                }
                if(i+1<grid.size()){
                    if(grid[i+1][j]==1){
                        q.push({i+1,j});
                        grid[i+1][j]=0;
                    }
                }
                if(j+1<grid[0].size()){
                    if(grid[i][j+1]==1){
                        q.push({i,j+1});
                        grid[i][j+1]=0;
                    }
                }
            }
            ans++;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0)return -1;
            }
        }
        return ans==0 ? 0 : ans-1;
    }
};