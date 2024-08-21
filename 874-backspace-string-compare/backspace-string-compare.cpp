class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ans1="",ans2="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='#' and ans1.size()!=0){
                ans1.pop_back();
            }
            else{
                if(s[i]!='#'){
                ans1=ans1+s[i];
                }
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#' and ans2.size()!=0){
                ans2.pop_back();
            }
            else{
                if(t[i]!='#'){
                ans2=ans2+t[i];
                }
            }
        }
        cout<<ans1<<" "<<ans2;
        if(ans1==ans2) return true;
        return false;
    }
};