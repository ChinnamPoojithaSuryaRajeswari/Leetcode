class Solution {
public:
    void bfs(vector<vector<char>> board,vector<vector<int>>& name,int i,int j){
        queue<pair<int,int>>q;
        cout<<"bfs"<<" ";
        q.push({i,j});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            name[x][y]=0;
            if(x-1>=0 and name[x-1][y]==-1 and board[x-1][y]=='O'){
                name[x-1][y]=0;
                q.push({x-1,y});
            }
            if(x+1<board.size() and name[x+1][y]==-1 and board[x+1][y]=='O'){
                name[x+1][y]=0;
                q.push({x+1,y});
            }
            if(y-1>=0 and name[x][y-1]==-1 and board[x][y-1]=='O'){
                name[x][y-1]=0;
                q.push({x,y-1});
            }
            if(y+1<board[x].size() and name[x][y+1]==-1 and board[x][y+1]=='O'){
                name[x][y+1]=0;
                q.push({x,y+1});
            }
            q.pop();
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> name(board.size(), vector<int>(board[0].size(), -1));
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O' and name[0][i]==-1){
                bfs(board,name,0,i);
            }
            if(board[board.size()-1][i]=='O' and name[name.size()-1][i]==-1){
                bfs(board,name,board.size()-1,i);
            }
        }
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O' and name[i][0]==-1){
                bfs(board,name,i,0);
            }
            if(board[i][board[i].size()-1]=='O' and name[i][name[i].size()-1]==-1){
                bfs(board,name,i,board[i].size()-1);
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='O'){
                    if(name[i][j]==-1){
                        board[i][j]='X';
                    }
                };
                cout<<name[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};