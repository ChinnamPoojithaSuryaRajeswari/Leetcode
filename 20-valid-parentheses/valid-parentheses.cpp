class Solution {
public:
    bool isValid(string x) {
        stack<char>st;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='(' or x[i]=='[' or x[i]=='{')
            {
                st.push(x[i]);
            }
            else if(st.empty()==0){
                if(x[i]==')' and st.top()=='('){
                    st.pop();
                }
                else if(x[i]==']' and st.top()=='[')
                {
                    st.pop();
                }
                else if(x[i]=='}' and st.top()=='{')
                {
                    st.pop();
                }
                else{
                    return false;
                }
        }
        else{
                    return false;
                }
        }
        if(st.empty()==1)
        {
            return true;
        }
        else{
            return false;
        }
    }
};