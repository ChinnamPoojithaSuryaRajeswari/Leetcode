class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
         int n = arr.size();
        int maxKadane = INT_MIN, currentMax = 0;
        for (int i = 0; i < n; i++) {
            currentMax += arr[i];
            maxKadane = max(maxKadane, currentMax);
            if (currentMax < 0) currentMax = 0; 
        }
        int minKadane = INT_MAX, currentMin = 0;
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
            currentMin += arr[i];
            minKadane = min(minKadane, currentMin);
            if (currentMin > 0) currentMin = 0;
        }
        if (totalSum == minKadane) {
            return maxKadane;
        }
        int maxCircular = totalSum - minKadane;
        return max(maxKadane, maxCircular);
    }
};