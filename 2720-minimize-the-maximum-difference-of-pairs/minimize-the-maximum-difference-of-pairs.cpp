class Solution {
public:
    int help(vector<int>& nums, int m) {
        int cnt = 0;
        int index = 0;
        int n = nums.size();
        while (index < n - 1) {
            if (nums[index + 1] - nums[index] <= m) {
                cnt++;
                index += 2; 
            } else {
                index++;
            }
        }
        return cnt;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int l = 0, h = nums.back() - nums.front();
        while (l < h) {
            int m = l + (h - l) / 2;
            int call = help(nums, m);
            if (call >= p) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};