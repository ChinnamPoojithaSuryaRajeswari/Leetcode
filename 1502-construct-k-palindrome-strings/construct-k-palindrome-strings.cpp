class Solution {
public:
    bool canConstruct(string s, int k) {
        map<int,int>mpp;
        for(int i=0;i<s.size();i++)mpp[s[i]]++;
        int o=0,c=0;
        if(s.size()<k)return false;
        for(auto it:mpp){
            if(it.second%2==1){
                o++;
            }
        }
        if(o>k)return false;
        return true;
    }
};