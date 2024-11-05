class Solution {
public:
    int minChanges(string s) {
        int i=0,cnt=0;
        while(i<s.size()-1){
            if(s[i]!=s[i+1]){
                cnt+=1;
            }
            i+=2;
        }
        return cnt;
    }
};