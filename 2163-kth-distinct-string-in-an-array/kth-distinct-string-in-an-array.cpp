class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int i=0;
        set<string>m;
        map<string,int>mpp;
        while(i<arr.size()){
            mpp[arr[i]]+=1;
            i+=1;
        }
        for(int i=0;i<arr.size();i++){
            if(mpp[arr[i]]==1){
                m.insert(arr[i]);
            }
            if(m.size()==k){
                return arr[i];
            }
        }
        return "";
    }
};