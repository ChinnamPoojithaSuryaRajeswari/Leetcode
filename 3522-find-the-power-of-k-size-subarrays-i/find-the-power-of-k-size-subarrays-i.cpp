class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
         vector<int>vec;
        vector<int>ans;
        int i=0,flag=0;
        for(i=0;i<k-1;i++){
            vec.push_back(nums[i]);
        }
        while(i<nums.size()){
            vec.push_back(nums[i]);
            flag=0;
            for(int j=0;j<vec.size()-1;j++){
                if(vec[j]!= vec[j+1]-1){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                ans.push_back(nums[i]);
            }
            else{
                ans.push_back(-1);
            }
            vec.erase(vec.begin());
            i+=1;
        }
        return ans;
    }
};