class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>ans;
        for(int i=0;i<arr.size();i++){
            ans[arr[i]]+=1;
        }
        vector<int>req;
        for(auto it:ans){
            req.push_back(it.second);
        }
        sort(req.begin(),req.end());
        int o;
        for(int i=0;i<req.size();i++){
            if(k-req[i]>0){
                k-=req[i];
            }
            else if(k-req[i]<0){
                o=i;
                break;
            }
            else{
                o=i+1;
                break;
            }
        }
        return req.size()-o;
    }
};