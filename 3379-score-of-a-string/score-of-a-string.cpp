class Solution {
public:
    int scoreOfString(string s) {
        int i=0,j=1,ans=0;
        while(j<s.size()){
            ans+=abs(int(s[i])-int(s[j]));
            i+=1;
            j+=1;
        }
        return ans;
    }
};