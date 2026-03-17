class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int res = 0;
        for (int i = 1; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (matrix[i][j] == 1)
                    matrix[i][j] += matrix[i - 1][j];
        for (int i = 0; i < matrix.size(); i++) {
            sort(matrix[i].rbegin(), matrix[i].rend());
            for (int j = 0; j < matrix[0].size(); j++)
                res = max(res, matrix[i][j] * (j + 1));
        }
        return res;

    }
};