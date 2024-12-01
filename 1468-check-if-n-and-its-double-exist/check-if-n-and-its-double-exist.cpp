class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int,int>mpp;
        for(int i=arr.size()-1;i>=0;i--){
            if(mpp[arr[i]*2]){
                return true;
            }
            if(arr[i]%2==0){
                if(mpp[arr[i]/2]){
                    return true;
                }
            }
            mpp[arr[i]]+=1;
        }
        return false;
    }
};