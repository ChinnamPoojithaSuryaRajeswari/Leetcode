class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size())return 0;
        int cnt=0;
        map<char,int>mpp;
        for(int i=0;i<s1.size();i++)mpp[s1[i]]++;
        for(int i=0;i<s2.size();i++){
            if(mpp[s2[i]]==0)return 0;
            mpp[s2[i]]--;
        }
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])cnt++;
        }
        return cnt<=2;
    }
};