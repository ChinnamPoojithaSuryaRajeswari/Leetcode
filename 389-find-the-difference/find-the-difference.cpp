class Solution {
public:
    char findTheDifference(string s, string t) {
        int x=0;
        for(int i=0;i<s.size();i++){
            x^=s[i];
        }
        for(int i=0;i<t.size();i++){
            x^=t[i];
        }
        return x;
    }
};