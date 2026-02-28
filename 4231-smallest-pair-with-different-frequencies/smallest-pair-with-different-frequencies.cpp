class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) 
            freq[x]++;

        vector<int> vals;
        vals.reserve(freq.size());
        for (auto &kv : freq) 
            vals.push_back(kv.first);
        sort(vals.begin(), vals.end());

        int d = vals.size();
        for (int i = 0; i < d; ++i) {
            int x = vals[i];
            for (int j = i + 1; j < d; ++j) {
                int y = vals[j];
                if (freq[x] != freq[y]) 
                    return {x, y};
            }
        }
        return {-1, -1};
    }
};