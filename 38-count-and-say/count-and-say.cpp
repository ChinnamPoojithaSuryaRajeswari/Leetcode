class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        n-=1;
        while(n>0){
            int i=0;
            string e="";
            while(i<s.size()){
                int c=1,j=i+1;
                while(j<s.size() &&s[i]==s[j]){
                    j+=1;
                    c+=1;
                }
                e+=to_string(c);
                e+=s[i];
                i=j;
            }
            s=e;
            n-=1;
        }
        return s;
    }
};