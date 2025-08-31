class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>row(9,vector<int>(9,0));
        vector<vector<int>>col(9,vector<int>(9,0));
        vector<vector<int>>griddy(9,vector<int>(9,0));
        int ressy=0;
        for(int i = 0 ; i < 8 ; i+=3){
            for(int j = 0 ; j < 8 ; j+=3){
                for(int k = i ; k < i+3; k++){
                    for(int l = j ; l < j+3 ; l++){
                        int val = board[k][l]-'0';
                        val-=1;
                        if(val>=0 && val<=8){
                            cout<<board[k][l]-'0'<<" ";
                            if(griddy[ressy][val]>0) return false;
                            if(row[k][val]>0) return false;
                            if(col[l][val]>0) return false;
                            row[k][val]+=1;
                            col[l][val]+=1;
                            griddy[ressy][val]+=1;
                        }
                    }
                }
                ressy+=1;
            }
        }
        return true;
    }
};