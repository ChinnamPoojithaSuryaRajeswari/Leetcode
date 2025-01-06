class Solution {
public:
    int rob(vector<int>& arr) {
        vector<int>dp(arr.size(),INT_MIN);
        if(arr.size()==2){
            return max(arr[0],arr[1]);
        }
        if(arr.size()==1)return arr[0];
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=1;i<arr.size();i++)
            if(i-2>=0){
                dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
            }
        
        return dp[arr.size()-1];
    }
};