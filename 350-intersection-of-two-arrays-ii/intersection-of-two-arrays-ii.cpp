class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m1;
        map<int,int>m2;
        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]]+=1;
        }
        for(int i=0;i<nums2.size();i++){
            m2[nums2[i]]+=1;
        }
        int k=0;
        vector<int>vec;
        for(auto it:m1){
            if(m2[it.first]!=0){
                if(it.second<=m2[it.first]){
                    k=it.second;
                }
                else{
                    k=m2[it.first];
                }
                for(int i=0;i<k;i++){
                    vec.push_back(it.first);
                }
            }
        }
        return vec;
    }
};