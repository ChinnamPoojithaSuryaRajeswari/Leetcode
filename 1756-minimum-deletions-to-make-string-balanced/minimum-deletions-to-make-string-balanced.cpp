class Solution {
public:
    int minimumDeletions(string s) {
        map<int,int>acount;
        map<int,int>bcount;
        int ac=0,bc=0;
        for(int i=0;i<s.size();i++){
            bcount[i]=bc;
            if(s[i]=='b'){
                bc+=1;
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            acount[i]=ac;
            if(s[i]=='a'){
                ac+=1;
            }
        }
        int ans = acount[0]+bcount[0];
        for(int i=0;i<s.size();i++){
            if(ans>acount[i]+bcount[i]){
                ans = acount[i]+bcount[i];
            }
        }
        return ans;
    }
};