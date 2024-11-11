class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) maxi = max(maxi,nums[i]);
        vector<int> prime(maxi,1);
        for(int i=2; i < maxi; i++){
            if(prime[i] == 1){
                for(int j = i+i; j < maxi; j += i){
                    prime[j] = 0;
                }
            }
        }
        int i = n-2;
        int res = nums[n-1];
        while(i >= 0){
            if(nums[i] >= res){
                int flag = 0;
                for(int j = 2; j < nums[i]; j++){
                    if(prime[j] == 1){
                        if(nums[i] - j < res){
                            nums[i] = nums[i] - j;
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag == 0) return false;
            }
            res = nums[i];
            i--;
        }
        return true;
    }
};