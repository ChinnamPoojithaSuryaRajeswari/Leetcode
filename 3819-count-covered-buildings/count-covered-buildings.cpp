class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxRow(n + 1);
        vector<int> minRow(n + 1, n + 1);
        vector<int> maxCol(n + 1);
        vector<int> minCol(n + 1, n + 1);
        for (auto& it : buildings) {
            int m = it[0], p = it[1];
            maxRow[p] = max(maxRow[p], m);
            minRow[p] = min(minRow[p], m);
            maxCol[m] = max(maxCol[m], p);
            minCol[m] = min(minCol[m], p);
        }
        int res = 0;
        for (auto& p : buildings) {
            int x = p[0], y = p[1];
            if (x > minRow[y] && x < maxRow[y] && y > minCol[x] &&
                y < maxCol[x]) {
                res++;
            }
        }
        return res;
    }
};