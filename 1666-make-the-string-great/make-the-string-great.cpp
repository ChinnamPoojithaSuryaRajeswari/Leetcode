class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(abs(int(st.top())-int(s[i]))==32){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        cout<<s;
        return s;
    }
};