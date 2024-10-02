class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]].push_back(i);
        }
        int cnt=1;
        for(auto it:mpp){
            for(int i=0;i<it.second.size();i++){
                arr[it.second[i]]=cnt;
            }
            cnt+=1;
        }
        return arr;
    }
};