class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int c=0,s=1,i=0;
        vector<int>product;
        for(i=0;i<nums.size();i++){
            if(nums[i]==0){
                c+=1;
            }
            else{
            s*=nums[i];
            }
        }
        i=0;
        if(c==0){
            while(i<nums.size()){
                product.push_back(s/nums[i]);
                i+=1;
            }
            return product;
        }
        else if(c==1){
            while(i<nums.size()){
                if(nums[i]==0){
                    product.push_back(s);
                }
                else{
                    product.push_back(0);
                }
                i+=1;
            }
            return product;
        }
        else{
            vector<int>ans(nums.size(),0);
            return ans;
        }
    }
};