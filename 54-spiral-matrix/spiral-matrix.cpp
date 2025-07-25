class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int east=matrix[0].size()-1,west=0,north=0,south=matrix.size()-1,front=1,back=0,top=0,down=0,i;
        vector<int> spiralMatrix;
        while(west<=east and north<=south){
            if(front==1){
                i=west;
                while(i<=east){
                    spiralMatrix.push_back(matrix[north][i]);
                    i+=1;
                }
                north+=1;
                down=1;
                front=0;
            }
            else if(down==1){
                i=north;
                while(i<=south){
                    spiralMatrix.push_back(matrix[i][east]);
                    i+=1;
                }
                east-=1;
                down=0;
                back=1;
            }
            else if(back==1){
                i=east;
                while(i>=west){
                    spiralMatrix.push_back(matrix[south][i]);
                    i-=1;
                }
                south-=1;
                back=0;
                top=1;
            }
            else{
                i=south;
                while(i>=north){
                    spiralMatrix.push_back(matrix[i][west]);
                    i-=1;
                }
                west+=1;
                top=0;
                front=1;
            }
        }
        return spiralMatrix;
    }
};