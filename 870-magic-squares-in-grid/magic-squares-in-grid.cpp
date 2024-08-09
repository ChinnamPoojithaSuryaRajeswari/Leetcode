class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count=0,ans=0;
        if(grid.size()<3 and grid[0].size()<3) return 0;
        for(int i=0;i<grid.size()-2;i++){
            for(int j=0;j<grid[0].size()-2;j++){
                vector<int>vec(9,0);
                vector<int>resq;
                count=0;
                if(grid[i][j]-1 <9 and grid[i][j]!=0){
                if(vec[grid[i][j]-1]==0){
                    vec[grid[i][j]-1]=1;
                    count+=1;
                    resq.push_back(grid[i][j]);
                }
                }
                if(grid[i][j+1]-1 <9 and grid[i][j+1]!=0){
                if(vec[grid[i][j+1]-1]==0){
                    vec[grid[i][j+1]-1]=1;
                    count+=1;
                    resq.push_back(grid[i][j+1]);
                }
                }
                if(grid[i][j+2]-1 < 9 and grid[i][j+2]!=0){
                if(vec[grid[i][j+2]-1]==0){
                    vec[grid[i][j+2]-1]=1;
                    count+=1;
                    resq.push_back(grid[i][j+2]);
                }
                }
                if(grid[i+1][j]-1 < 9 and grid[i+1][j]!=0){
                if(vec[grid[i+1][j]-1]==0){
                    vec[grid[i+1][j]-1]=1;
                    count+=1;
                    resq.push_back(grid[i+1][j]);
                }
                }
                if(grid[i+1][j+1]-1 < 9 and grid[i+1][j+1]!=0){
                if(vec[grid[i+1][j+1]-1]==0){
                    vec[grid[i+1][j+1]-1]=1;
                    count+=1;
                    resq.push_back(grid[i+1][j+1]);
                }
                }
                if(grid[i+1][j+2]-1 < 9 and grid[i+1][j+2]!=0){
                if(vec[grid[i+1][j+2]-1]==0){
                    vec[grid[i+1][j+2]-1]=1;
                    count+=1;
                    resq.push_back(grid[i+1][j+2]);
                }
                }
                if(grid[i+2][j]-1 < 9 and grid[i+2][j]!=0){
                if(vec[grid[i+2][j]-1]==0){
                    vec[grid[i+2][j]-1]=1;
                    count+=1;
                    resq.push_back(grid[i+2][j]);
                }
                }
                if(grid[i+2][j+1]-1 < 9 and grid[i+2][j+1]!=0){
                if(vec[grid[i+2][j+1]-1]==0){
                    vec[grid[i+2][j+1]-1]=1;
                    count+=1;
                    resq.push_back(grid[i+2][j+1]);
                }
                }
                if(grid[i+2][j+2]-1 < 9 and grid[i+2][j+2]!=0){
                if(vec[grid[i+2][j+2]-1]==0){
                    vec[grid[i+2][j+2]-1]=1;
                    count+=1;
                    resq.push_back(grid[i+2][j+2]);
                }
                }
                if(count==9){
                    if(resq[0]+resq[4]+resq[8]==resq[2]+resq[4]+resq[6] and resq[0]+resq[1]+resq[2]==resq[0]+resq[4]+resq[8] and resq[3]+resq[4]+resq[5]==resq[0]+resq[4]+resq[8] and resq[6]+resq[7]+resq[8]==resq[0]+resq[4]+resq[8] and
                      resq[0]+resq[3]+resq[6]==resq[0]+resq[4]+resq[8] and 
                      resq[1]+resq[4]+resq[7]==resq[0]+resq[4]+resq[8] and
                      resq[2]+resq[5]+resq[8]==resq[0]+resq[4]+resq[8]){
                    ans+=1;
                   }
                }
                resq.clear();
                vec.clear();
            }
        }
        return ans;
    }
};