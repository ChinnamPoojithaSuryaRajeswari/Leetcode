class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c=0;
        for(int i=0;i<words.size();i++){
            int flag=0;
            for(int j=0;j<pref.size();j++){
                if(pref[j]!=words[i][j]){
                    flag=1;
                    break;
                }
            }
            if(flag)continue;
            c++;
        }
        return c;
    }
};