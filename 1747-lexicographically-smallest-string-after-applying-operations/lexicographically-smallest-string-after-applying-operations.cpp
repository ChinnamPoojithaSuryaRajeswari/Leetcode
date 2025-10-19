class Solution {
public:
    void dfs(string s, int a, int b, unordered_set<string>& visited, string& ans) {
        if (visited.count(s)) return;
        visited.insert(s);
        ans = min(ans, s); 
        string added = s;
        for (int i = 1; i < added.size(); i += 2) {
            int digit = (added[i] - '0' + a) % 10;
            added[i] = '0' + digit;
        }
        dfs(added, a, b, visited, ans);
        string rotated = s.substr(s.size() - b) + s.substr(0, s.size() - b);
        dfs(rotated, a, b, visited, ans); 
       }
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        string ans = s;
        dfs(s, a, b, visited, ans);
        return ans;
    }
};