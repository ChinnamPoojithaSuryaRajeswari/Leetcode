class Solution {
public:
    void Queens(vector<vector<string>>& ans,vector<string>&vec,
        vector<int>row,vector<int>topDiagonal,vector<int>bottomDiagonal,int col,int size){
        if(col >= size){
            ans.push_back(vec);
            return;
        }
        for(int i=0;i<size;i++){
            if(row[i]==0 && topDiagonal[size-1+col-i]==0 && bottomDiagonal[col+i]==0){
                vec[i][col]='Q';
                row[i]=1;
                topDiagonal[size-1+col-i]=1;
                bottomDiagonal[col+i]=1;
                Queens(ans,vec,row,topDiagonal,bottomDiagonal,col+1,size);
                vec[i][col]='.';
                row[i]=0;
                topDiagonal[size-1+col-i]=0;
                bottomDiagonal[col+i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>vec;
        string s(n,'.');
        for(int i=0;i<n;i++){
            vec.push_back(s);
        }
        vector<int>row(n,0);
        vector<int>topDiagonal(100,0);
        vector<int>bottomDiagonal(100,0);
        Queens(ans,vec,row,topDiagonal,bottomDiagonal,0,n);
        return ans;
    }
};