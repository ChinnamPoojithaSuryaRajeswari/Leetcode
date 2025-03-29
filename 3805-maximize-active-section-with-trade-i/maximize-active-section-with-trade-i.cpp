class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int res=0,cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                cnt+=1;
            }
        }
        res=cnt;
        int i=0;
        int a=0,b=0,c=0;
        while(i<s.size()){
            if(s[i]=='0' || a!=0){
                b=0;
                c=0;
                while(i<s.size() && s[i]=='0'){
                    a+=1;
                    i+=1;
                }
                while(i<s.size() && s[i]=='1'){
                    b+=1;
                    i+=1;
                }
                while(i<s.size() && s[i]=='0'){
                    c+=1;
                    i+=1;
                }
                if(a!=0 && b!=0 && c!=0){
                    res=max(res,cnt+a+c);
                }
                a=c;
            }
            else{
                i+=1;
            }
        }
        return res;
    }
};