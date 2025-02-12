class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int &ans){
        if(i<0 or i>=grid.size() or j<0 or  j>=grid[0].size()) return;
        if(grid[i][j]==0) return;
        ans+=1;
        grid[i][j]=0;
        dfs(grid,i+1,j,ans);
        dfs(grid,i-1,j,ans);
        dfs(grid,i,j+1,ans);
        dfs(grid,i,j-1,ans);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int ans = 0;
                if(grid[i][j]==1)dfs(grid,i,j,ans);
                result = max(result,ans);
            }
        }
        return result;
    }
};