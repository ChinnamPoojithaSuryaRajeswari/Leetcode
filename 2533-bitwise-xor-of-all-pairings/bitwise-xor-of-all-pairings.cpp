class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()%2==0 && nums2.size()%2==0)return 0;
        int s=0,k=0;
        for(int i=0;i<nums1.size();i++)s=s^nums1[i];
        for(int i=0;i<nums2.size();i++)k=k^nums2[i];
        if(nums1.size()%2==1 and nums2.size()%2==1)return k^s;
        if(nums1.size()%2==1)return k;
        return s;
    }
};