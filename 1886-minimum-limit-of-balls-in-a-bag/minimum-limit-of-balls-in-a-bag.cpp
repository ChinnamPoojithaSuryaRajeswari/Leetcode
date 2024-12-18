class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,h=*max_element(nums.begin(),nums.end()),maxi=h;
        while(l<=h){
            int m = (l+h)/2,cnt=0;
            for(int i=0;i<nums.size();i++){
                cnt=cnt+(nums[i]/m);
                if(nums[i]%m==0){
                    cnt-=1;
                }
            }
            if(cnt<=maxOperations){
                maxi=min(m,maxi);
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return maxi;
    }
};