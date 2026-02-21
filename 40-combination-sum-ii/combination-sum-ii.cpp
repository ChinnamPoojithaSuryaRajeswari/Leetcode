class Solution {
public:
    void help(vector<int>& candidates, int target, int start,
        vector<int>& ans, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(ans);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            ans.push_back(candidates[i]);
            help(candidates, target - candidates[i], i + 1, ans, res);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ans;
        help(candidates, target, 0, ans, res);
        return res;
    }
};