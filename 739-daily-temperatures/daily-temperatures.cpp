class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        stack<int>s;
        vector<int>ans;
        for(int i=temperatures.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(temperatures[i]);
                s.push(i);
                ans.push_back(0);
            }
            else{
                while(!st.empty() and st.top()<=temperatures[i]){
                    st.pop();
                    s.pop();
                }
                if(st.empty()){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(s.top()-i);
                }
                st.push(temperatures[i]);
                s.push(i);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};