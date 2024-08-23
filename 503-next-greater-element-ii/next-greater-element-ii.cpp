class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans;
        ans = nums;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        map<int,int>mpp;
        stack<int>st;
        for(int i=ans.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(ans[i]);
                if(i<nums.size()){
                    nums[i]=-1;
                }
            }
            else{
                while(!st.empty() and st.top()<=ans[i]){
                    st.pop();
                }
                if(st.empty()){
                    if(i<nums.size()){
                    nums[i]=-1;
                    }
                }
                else{
                    if(i<nums.size()){
                    nums[i]=st.top();
                    }
                }
                st.push(ans[i]);
            }
        }
        return nums;
    }
};