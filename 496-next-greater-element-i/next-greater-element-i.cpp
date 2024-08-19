class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mpp;
        stack<int>st;
        vector<int>vec;
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(nums2[i]);
                mpp[nums2[i]]=-1;
            }
            else{
                while(!st.empty() and nums2[i] >= st.top()){
                    st.pop();
                }
                if(st.empty()){
                    mpp[nums2[i]]=-1;
                }
                else{
                    mpp[nums2[i]]=st.top();
                }
                st.push(nums2[i]);
            }
        }
        for(int i=0;i<nums1.size();i++){
            vec.push_back(mpp[nums1[i]]);
        }
        return vec;
    }
};