class Solution {
public:
    int calculate(vector<int>&nums,int val){
        int l=0,h=nums.size()-1,ind=-1;
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m]<val)ind = max(ind,m);
            if(nums[m]>=val){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ind;
    }
    int triangleNumber(vector<int>& nums) {
        int answer=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            for(int j=i+1;j<nums.size();j++){
                val+=nums[j];
                int index = calculate(nums,val);
                val-=nums[j];
                if(index!=-1 and index>j)answer += index-j;
            }
        }
        return answer;
    }
};