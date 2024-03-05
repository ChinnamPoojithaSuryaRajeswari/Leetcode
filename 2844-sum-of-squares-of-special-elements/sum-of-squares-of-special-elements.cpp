class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int q=nums.size(),k=1,s=0;
        for(int i=0;i<nums.size();i++){
            if(q%k==0){
                s+=nums[k-1]*nums[k-1];
            }
            k+=1;
        }
        return s;
    }
};