class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp;
        dp.push_back(0);
        if(n==0)return dp;
        dp.push_back(1);
        int cnt=0,i=1;
        for(i=2;i<=n;i*=2){
            for(int j=i;j<i*2;j++){
                if(j>n)break;
                dp.push_back(cnt+1+dp[j-i]);
            }
        }
        return dp;
    }
};