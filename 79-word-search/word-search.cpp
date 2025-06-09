class Solution {
public:
    bool flag = false;
    void callForSearch(vector<vector<char>>&board,vector<vector<int>>&visited,int i,int j,string &word,int k){
        if(k>=word.size()){
            flag = true;
            return;
        }
        if(i>=board.size() || i<0 || j>=board[0].size() || j<0)return;
        if(flag)return;
        if(visited[i][j]==1)return;
        if(board[i][j]==word[k]){
            visited[i][j]=1;
            callForSearch(board,visited,i+1,j,word,k+1);
            callForSearch(board,visited,i-1,j,word,k+1);
            callForSearch(board,visited,i,j+1,word,k+1);
            callForSearch(board,visited,i,j-1,word,k+1);
        }
        visited[i][j]=0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(word[0]==board[i][j])callForSearch(board,visited,i,j,word,0);
                if(flag)return true;
            }
        }
        return flag;
    }
};