class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(nums[i]);
            }
            else{
                while(!st.empty() and st.top()<=nums[i]){
                    st.pop();
                }
                st.push(nums[i]);
            }
        }
         for(int i=nums.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(nums[i]);
                    nums[i]=-1;
            }
            else{
                while(!st.empty() and st.top()<=nums[i]){
                    st.pop();
                }
                int k = nums[i];
                if(st.empty()){
                    nums[i]=-1;
                }
                else{
                    nums[i]=st.top();
                }
                st.push(k);
            }
        }
        return nums;
    }
};