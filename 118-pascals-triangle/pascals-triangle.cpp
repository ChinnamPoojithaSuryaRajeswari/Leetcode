class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        res.push_back({1});
        if(numRows==1)return res;
        res.push_back({1,1});
        for(int i=2;i<numRows;i++){
            vector<int>p;
            p.push_back(1);
            for(int j=1;j<i;j++){
                p.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            p.push_back(1);
            res.push_back(p);
            p.clear();
        }
        return res;
    }
};