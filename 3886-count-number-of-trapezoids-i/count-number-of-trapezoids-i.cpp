class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> m;
        const int mod = 1e9 + 7;
        for (auto P : points) {
            m[P[1]]++;
        }
        vector<long long> levelPoints;
        for (auto P : m)
            levelPoints.push_back(P.second);
        vector<long long> levelPairs;
        for (long long p : levelPoints) {
            if (p < 2) {
                levelPairs.push_back(0);
            } else {
                long long  x = (((p%mod) * (((p%mod) - 1)%mod) )%mod) / 2; 
                levelPairs.push_back(x);
            }
        }
        long long sum = accumulate(levelPairs.begin(), levelPairs.end(), 0LL);
        long long ans = 0;
         for (int i = 0; i < levelPairs.size(); i++) {
            sum -= levelPairs[i];
            ans += levelPairs[i] * sum;
            ans %= mod;
        }
        return ans % mod;
    }
};