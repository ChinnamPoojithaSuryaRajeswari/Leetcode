class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>v;
        int c=0,p=0,i=0,j=0;
        while(i<s.size()){
            if(v[int(s[i])]==0){
                v[int(s[i])]=1;
                i+=1;
            }
            else{
                p = max(p,i-j);
                cout<<p<<" "<<i<<" "<<j<<endl;
                while(s[i]!=s[j]){
                    v[int(s[j])]--;
                    j++;
                }
                    v[int(s[j])]--;
                    j++;
            }
        }
        p=max(p,i-j);
        return p;
    }
};