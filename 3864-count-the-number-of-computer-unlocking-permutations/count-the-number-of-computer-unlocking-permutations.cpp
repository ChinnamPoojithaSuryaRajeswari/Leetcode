class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int p = complexity[0],mod = 1e9+7;
        for (int i = 1; i < complexity.size(); i++) {
            if (complexity[i] <= p) return 0;
        }
        long long ans = 1;
        for (int i = 2; i < complexity.size(); i++) {
            ans = (ans * i) % mod;
        }
        return (int)ans;
    }
};