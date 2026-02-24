class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int,int>reach;
        int val=1,flag=1;
        for(int i=board.size()-1;i>=0;i--){
            if(flag){
                flag = !flag;
                int j = 0;
                while(j<board[i].size()){
                    if(board[i][j]!=-1)reach[val]=board[i][j];
                    val++;
                    j++;
                }
            }
            else{
                flag = !flag;
                int j = board[i].size()-1;
                while(j>=0){
                    if(board[i][j]!=-1)reach[val]=board[i][j];
                    val++;
                    j--;
                }
            }
        }
        vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),INT_MAX));
        queue<pair<int,int>>q;
        q.push({1,0});
        while(!q.empty()){
            int current = q.front().first;
            int step = q.front().second;
            int res = board.size()*board.size();
            for(int i = 1; i <= 6 && current + i <= res; i++){
                int pooji = current+i;
                if(visited[(pooji-1)/board.size()][(pooji-1)%board.size()] > step+1 and reach[current+i]==0){
                    visited[(pooji-1)/board.size()][(pooji-1)%board.size()] = step+1;
                    q.push({current+i,step+1});
                }
                if(reach[current+i]){
                    int reddy = reach[current+i];
                    if(reach[current+i] > current + i){
                        if(visited[(reddy-1)/board.size()][(reddy-1)%board.size()] > step+1){
                            visited[(reddy-1)/board.size()][(reddy-1)%board.size()] = step+1;
                            q.push({reach[current+i],step+1});
                        }
                    }
                    else{
                        if(visited[(reddy-1)/board.size()][(reddy-1)%board.size()] > step+1){
                            visited[(reddy-1)/board.size()][(reddy-1)%board.size()] = step+1;
                            q.push({reach[current+i],step+1});
                        }
                    }
                }
            }
            q.pop();
        }
        // cout<<visited[board.size()-1][board.size()-1];
        return visited[board.size()-1][board.size()-1]==INT_MAX ? -1:visited[board.size()-1][board.size()-1];
    }
};