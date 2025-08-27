class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int i=0,j=0,n=mat.size(),m=mat[0].size(),d=1;
        while(i<n && j<m){
            ans.push_back(mat[i][j]);
            if(d==1){
                if(i-1>=0 && j+1<m){
                    i-=1;
                    j+=1;
                }
                else if(j+1<m){
                    d=0;
                    j+=1;
                }
                else if(i+1<n){
                    d=0;
                    i+=1;
                }
                else{
                    break;
                }
            }
            else{
                if(i+1<n && j-1>=0){
                    i+=1;
                    j-=1;
                }
                else if(i+1<n){
                    d=1;
                    i+=1;
                }
                else if(j+1<m){
                    d=1;
                    j+=1;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};