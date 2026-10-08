class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        int i=1,l=1,r=0,cnt=0;
        string ans="";
        st.push('(');
        while(i<s.size()){
            st.push(s[i]);
            if(s[i]=='('){
                l+=1;
            }
            else {
                r+=1;
            }
            if(l==r){
                s.erase(s.begin()+i);
                s.erase(s.begin()+(i-st.size()+1));
                cnt+=2;
                while(!st.empty()){
                    st.pop();
                }
                l=0;
                r=0;
                if(i==s.size()+2-1){
                    break;
                }
                i-=2;
            }
            i+=1;
        }
        i=s.size()-1;
        if(l==r and l!=0 and r!=0){
            s.erase(s.begin()+i);
            s.erase(s.begin()+(i-st.size()+1-cnt));
            }
        return s;
    }
};