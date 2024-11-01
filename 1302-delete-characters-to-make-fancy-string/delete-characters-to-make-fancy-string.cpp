class Solution {
public:
    string makeFancyString(string s) {
        stack<pair<char, int>> st;
        string ans = "";
        for (char c : s) {
            if (st.empty() || st.top().first != c) {
                st.push({c, 1});
                ans += c;
            } 
            else {
                if (st.top().second < 2) {
                    st.top().second += 1;
                    ans += c;
                }
            }
        }
        return ans;
    }
};