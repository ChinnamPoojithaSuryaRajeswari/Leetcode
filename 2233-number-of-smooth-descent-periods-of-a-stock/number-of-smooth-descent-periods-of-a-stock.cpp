class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 1,ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i] - prices[i-1]==-1){
                res++;
            }
            else {
                ans += (res*(res+1))/2;
                res=1;
            }
        }
        ans += (res*(res+1))/2;
        return ans;
    }
};