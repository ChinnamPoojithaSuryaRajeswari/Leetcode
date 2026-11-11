class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
         long long ans = min(costBoth,cost1+cost2);
         ans = ans * (min(need1,need2));
         ans += ((need1-min(need1,need2))*min(cost1,costBoth));
         ans += ((need2-min(need1,need2))*min(costBoth,cost2));
         return ans;
    }
};