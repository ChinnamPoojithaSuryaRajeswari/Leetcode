class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (auto  w:wordDict) {
                int start = i - w.size();
                if (start >= 0 && dp[start] && s.substr(start, w.size()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()]; 
    }
};