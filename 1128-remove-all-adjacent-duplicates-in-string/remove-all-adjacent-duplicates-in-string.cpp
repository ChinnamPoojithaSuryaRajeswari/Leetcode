class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        st.push(s[0]);
        string ans="";
        int i=1;
        while(i<s.size()){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
            if(st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            }
            i+=1;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};