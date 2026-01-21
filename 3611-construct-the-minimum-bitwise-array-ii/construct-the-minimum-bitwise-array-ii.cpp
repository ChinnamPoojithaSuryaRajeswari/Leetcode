class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int i = 0 ; i < nums.size() ; i++ ) {
            int k = nums[i], m = -1, p = 0;
            if(nums[i]>2){
                while(k >= (1<<p)){
                    if(((k^(1<<p))|(((k^(1<<p))+1)))==nums[i]){
                        m = (k^(1<<p));
                    }
                    // cout<<k<<" "<<(k^(1<<p))<<" ";
                    p+=1;
                }
                // cout<<endl;
                ans.push_back(m);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};