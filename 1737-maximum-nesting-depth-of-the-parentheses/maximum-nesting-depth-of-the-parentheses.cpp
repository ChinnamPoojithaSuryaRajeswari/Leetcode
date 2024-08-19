class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int max=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push('(');
            }
            if(s[i] == ')'){
                st.pop();
                if(max < st.size()+1){
                    max = st.size()+1;
                }
            }
        }
        return max;
    }
};