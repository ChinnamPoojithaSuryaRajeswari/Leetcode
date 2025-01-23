class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        // vector<int>row(grid.size(),0);
        // vector<int>col(grid[0].size(),0);
        // queue<pair<int,int>>q;
        // q.push({0,0});
        // int val=0;
        // while(!q.empty()){
        //     int i = q.front().first;
        //     int j = q.front().second;
        //     q.pop();
        //     dp[i][j]=1;
        //     if(grid[i][j]==1 and (row[i]!=0 or col[j]!=0)){
        //         row[i]+=1;
        //         col[j]+=1;
        //         val++;
        //     }
        //     else if(grid[i][j]==1){
        //         col[j]+=1;
        //         row[i]+=1;
        //     }
        //     if(i-1>=0){
        //         if(dp[i-1][j]==-1){
        //             q.push({i-1,j});
        //         }
        //         dp[i-1][j]=0;
        //     }
        //     if(i+1<grid.size()){
        //         if(dp[i+1][j]==-1){
        //             q.push({i+1,j});
        //         }
        //         dp[i+1][j]=0;
        //     }
        //     if(j-1>=0){
        //         if(dp[i][j-1]==-1){
        //             q.push({i,j-1});
        //         }
        //         dp[i][j-1]=0;
        //     }
        //     if(j+1<grid[0].size()){
        //          if(dp[i][j+1]==-1){
        //             q.push({i,j+1});
        //         }
        //         dp[i][j+1]=0;
        //     }
        // }
        // return val;
        vector<int>r,c;
        int s=0;
        for(int i=0;i<grid.size();i++){
            s=0;
            for(int j=0;j<grid[0].size();j++){
                s+=grid[i][j];
            }
            r.push_back(s);
        }
        for(int i=0;i<grid[0].size();i++){
            s=0;
            for(int j=0;j<grid.size();j++){
                s+=grid[j][i];
            }
            c.push_back(s);
        }
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 and (r[i]>1 or c[j]>1)){
                    res+=1;
                }
            }
            r.push_back(s);
        }
        return res;
    }
};