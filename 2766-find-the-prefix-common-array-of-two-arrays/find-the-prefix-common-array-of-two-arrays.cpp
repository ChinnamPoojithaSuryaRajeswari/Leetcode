class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int>a;
        int c=0;
        vector<int>ans;
        for(int i=0;i<A.size();i++){
            a[A[i]]++;
            a[B[i]]++;
            if(a[B[i]]==2)c++;
            if(a[A[i]]==2 and A[i]!=B[i])c++;
            ans.push_back(c);
        }
        return ans;
    }
};