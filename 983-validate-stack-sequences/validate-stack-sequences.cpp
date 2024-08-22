class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i=0,j=0;
        while(i<=pushed.size() and j<popped.size()){
            if(st.empty()){
                if(i==pushed.size()){
                        return false;
                    }
                st.push(pushed[i]);
                i+=1;
                if(st.top()==popped[j]){
                    st.pop();
                    j+=1;
                }
            }
            else{
                if(st.top()==popped[j]){
                    st.pop();
                    j+=1;
                }
                else{
                    if(i==pushed.size()){
                        return false;
                    }
                    st.push(pushed[i]);
                i+=1;
                }
            }
        }
        if(j==popped.size()) return true;
        return false;
    }
};