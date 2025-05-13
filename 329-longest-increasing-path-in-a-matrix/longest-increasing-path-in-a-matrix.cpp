class Solution {
public:
    int call(vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j, int prev) {
        if(i >= matrix.size() || i < 0 || j >= matrix[0].size() || j < 0) return 0;
        if(matrix[i][j] <= prev) return 0;
        if(visited[i][j] != 0) return visited[i][j];
        int left = call(matrix, visited, i, j - 1, matrix[i][j]);
        int right = call(matrix, visited, i, j + 1, matrix[i][j]);
        int up = call(matrix, visited, i - 1, j, matrix[i][j]);
        int down = call(matrix, visited, i + 1, j, matrix[i][j]);
        visited[i][j] = 1 + max({left, right, up, down});
        return visited[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>visited(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans = 0;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                ans= max(ans,call(matrix,visited,i,j,INT_MIN));
            }
        }
        return ans==0 ? 1:ans;
    }
};