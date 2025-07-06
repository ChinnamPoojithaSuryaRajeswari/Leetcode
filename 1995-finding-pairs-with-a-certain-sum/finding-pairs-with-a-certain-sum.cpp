class FindSumPairs {
public:
    unordered_map<int,int>n1;
    unordered_map<int,int>n2;
    vector<int>nummy;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();i++){
            n1[nums1[i]]+=1;
        }
        for(int j=0;j<nums2.size();j++){
            n2[nums2[j]]+=1;
            nummy.push_back(nums2[j]);
        }
    }
    
    void add(int index, int val) {
        n2[nummy[index]]-=1;
        nummy[index]+=val;
        n2[nummy[index]]+=1;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(auto it:n2){
            if(n1[tot-it.first]!=0){
                cnt+=(it.second*n1[tot-it.first]);
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */