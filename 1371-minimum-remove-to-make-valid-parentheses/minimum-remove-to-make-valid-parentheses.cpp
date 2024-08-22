class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                st.push(i);
                i+=1;
            }
            else if(s[i]==')'){
                if(st.empty()){
                   s.erase(s.begin()+i); 
                }
                else{
                    i+=1;
                    st.pop();
                }
            }
            else{
                i+=1;
            }
        }
        while(!st.empty()){
            s.erase(s.begin()+st.top());
            st.pop();
        }
        return s;
    }
};