class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                if(s[i]=='('){
                    st.push(i);
                }
                else{
                    s[i]='0';
                }
            }
            else{
                if(s[i]=='('){
                    st.push(i);
                }
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            s[st.top()]='0';
            st.pop();
        }
        int maxi = 0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(maxi < c){
                    maxi = c;
                }
                c=0;
                while(!st.empty()){
                    st.pop();
                }
            }
            else if(st.empty()){
                if(s[i]=='('){
                    st.push(s[i]);
                }
            }
            else if(!st.empty()){
                if(s[i]=='('){
                    st.push(s[i]);
                }
                else{
                    st.pop();
                    c+=2;
                }
            }
        }
        if(maxi < c){
                    maxi = c;
                }
        return maxi;
    }
};