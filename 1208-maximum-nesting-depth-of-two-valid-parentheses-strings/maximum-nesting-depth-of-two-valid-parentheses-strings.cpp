class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<int>st;
        vector<int> ans(seq.size(),-1);
        int flag=0;
        for(int i=0;i<seq.size();i++){
            if(st.empty()){
                flag=0;
            }
            if(seq[i]=='('){
                st.push(i);
                flag=flag^1;
            }
            else{
                ans[st.top()]=flag;
                ans[i]=flag;
                flag=flag^1;
                st.pop();
            }
        }
        return ans;
    }
};