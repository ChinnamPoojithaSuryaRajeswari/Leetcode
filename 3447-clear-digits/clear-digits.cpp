class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]>=97 and s[i]<=122){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        string res="";
        char ch;
        while(!st.empty()){
            ch=st.top();
            st.pop();
            res=ch+res;
        }
        return res;
    }
};