class Solution {
public:
    void call(vector<vector<char>>&grid,vector<vector<int>>&visited,int i,int j){
        if(i>=grid.size() or i<0 or j>=grid[0].size() or j<0)return;
        if(visited[i][j]==1 or grid[i][j]=='.')return;
        visited[i][j] = 1;
        call(grid,visited,i+1,j);
        call(grid,visited,i-1,j);
        call(grid,visited,i,j+1);
        call(grid,visited,i,j-1);
    }
    int countBattleships(vector<vector<char>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int  j = 0 ; j < grid[i].size() ; j++){
                if(visited[i][j]==0 and grid[i][j]=='X'){
                    call(grid,visited,i,j);
                    ans+=1;
                }
            }
        }
        return ans;
    }
};