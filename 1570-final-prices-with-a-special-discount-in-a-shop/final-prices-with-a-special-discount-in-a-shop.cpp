class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
         map<int,int>mpp;
        stack<int>st;
        vector<int>vec;
        for(int i=prices.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(prices[i]);
                // mpp[prices[i]]=0;
                vec.push_back(prices[i]);
            }
            else{
                while(!st.empty() and prices[i] < st.top()){
                    st.pop();
                }
                if(st.empty()){
                    // mpp[prices[i]]=0;
                    vec.push_back(prices[i]);
                }
                else{
                    // mpp[prices[i]]=st.top();
                    vec.push_back(prices[i]-st.top());
                }
                st.push(prices[i]);
            }
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};