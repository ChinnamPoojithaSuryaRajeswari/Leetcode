class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<vector<int>>matty;
        vector<int> vec;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                vec.push_back(0);
            }
            matty.push_back(vec);
            vec.clear();
        }
        vector<int>resq;
        int s=0;
        for(int i=0;i<matrix.size();i++){
            s=s^matrix[i][0];
            matty[i][0]=s;
            resq.push_back(s);
        }
        s=0;
        for(int j=0;j<matrix[0].size();j++){
            s=s^matrix[0][j];
            matty[0][j]=s;
            if(j!=0){
             resq.push_back(s);}
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i!=0 and j!=0){
                    matty[i][j]=matrix[i][j]^matty[i-1][j]^matty[i][j-1]^matty[i-1][j-1];
                     resq.push_back(matty[i-1][j]^matty[i][j-1]^matty[i-1][j-1]^matrix[i][j]);
                }
            }
        }
        sort(resq.begin(),resq.end());
        // for(int i=0;i<resq.size();i++){
        //     cout<<resq[i]<<" ";
        // }
        return resq[resq.size()-k];
    }
};