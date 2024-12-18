class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        vector<int>ans;
        for(int i=prices.size()-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(prices[i]);
                st.push(prices[i]);
            }
            else{
                while(!st.empty()){
                    if(st.top()>prices[i]){
                        st.pop();
                    }
                    else{
                        break;
                    }
                }
                if(!st.empty()){
                    ans.push_back(prices[i]-st.top());
                }
                else{
                    ans.push_back(prices[i]);
                }
                st.push(prices[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};