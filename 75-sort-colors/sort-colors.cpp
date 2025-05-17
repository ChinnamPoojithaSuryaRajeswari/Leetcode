class Solution {
public:
    void sortColors(vector<int>& nums) {
        int temp,c=0;
        for(int i=0;i<nums.size();i++){
            c=0;
            for(int j=0;j<nums.size()-i-1;j++){
                if(nums[j]>nums[j+1]){
                    temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                    c+=1;
                    }
                }
            if(c==0) break;
}
    }
};