class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,mini=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i] >= mini){
                ans+=(prices[i]-mini);
            }
            mini = prices[i];
        }
        return ans;
    }
};