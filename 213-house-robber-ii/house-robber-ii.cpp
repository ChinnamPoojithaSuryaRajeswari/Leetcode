class Solution {
public:
    // int rob(vector<int>& arr) {
    //     vector<int>dp(arr.size(),INT_MIN);
    //     if(arr.size()==3)return max(arr[0],max(arr[1],arr[2]));
    //     if(arr.size()==2){
    //         return max(arr[0],arr[1]);
    //     }
    //     if(arr.size()==1)return arr[0];
    //     dp[1]=arr[1];
    //     dp[2]=max(arr[2],arr[1]);
    //     for(int i=2;i<arr.size();i++){
    //         if(i-2>=0){
    //             dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
    //         }
    //     }
    //     vector<int>pd(arr.size()-1,INT_MIN);
    //     pd[0]=arr[0];
    //     pd[1]=max(arr[0],arr[1]);
    //     for(int i=2;i<arr.size()-1;i++){
    //         if(i-2>=0){
    //             pd[i]=max(pd[i-1],arr[i]+pd[i-2]);
    //         }
    //     }
    //     return max(dp[arr.size()-1],pd[arr.size()-2]);
    // }
    int rob(vector<int>& arr) {
    int n = arr.size();
    
    // Base cases for small arrays
    if (n == 1) return arr[0];
    if (n == 2) return max(arr[0], arr[1]);
    if (n == 3) return max(arr[0], max(arr[1], arr[2]));
    
    // Helper function to calculate the maximum robbery for a linear sequence
    auto calculateRobbery = [](vector<int>& nums) -> int {
        int size = nums.size();
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[size - 1];
    };
    
    // Case 1: Rob from 0 to n-2 (excluding the last house)
    vector<int> case1(arr.begin(), arr.end() - 1);
    int result1 = calculateRobbery(case1);
    
    // Case 2: Rob from 1 to n-1 (excluding the first house)
    vector<int> case2(arr.begin() + 1, arr.end());
    int result2 = calculateRobbery(case2);
    
    // Return the maximum of both cases
    return max(result1, result2);
}

};