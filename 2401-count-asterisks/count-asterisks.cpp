class Solution {
public:
    int countAsterisks(string s) {
        int cnt=0;
        stack<int>st;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='|'){
                st.push(i);
            }
        }
        int i,j;
        if(!st.empty()) st.pop();
        while(!st.empty()){
            j=-1;
            i=1;
            if(!st.empty()){
                i=st.top();
                st.pop();
            }
            if(!st.empty()){
                j=st.top();
                st.pop();
            }
            while(i<=j){
                if(s[i]=='*'){
                    cnt+=1;
                }
                i+=1;
            }
        }
        int mxi =-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='|'){
                mxi =i ;
                break;}
            if(s[i]=='*')cnt+=1;
        }
        if(mxi!=-1){
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='|')break;
            if(s[i]=='*')cnt+=1;
        }
        }
        return cnt;
    }
};