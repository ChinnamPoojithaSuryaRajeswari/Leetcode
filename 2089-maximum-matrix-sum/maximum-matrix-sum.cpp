class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int val = 0 , small = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans+=abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    val++;
                    small = min(small,(-1)*matrix[i][j]);
                }
                else{
                    small = min(small,matrix[i][j]);
                }
            }
        }
        if(val%2){
            // cout<<small<<" ";
            ans -= (2*small);
        }
        return ans;
    }
};