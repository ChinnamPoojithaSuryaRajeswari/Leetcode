class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>v(501,0);
        for(int i=0;i<arr.size();i++){
            v[arr[i]]+=1;
        }
        int ans=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==v[arr[i]]){
                ans=max(ans,arr[i]);
            }
        }
        return ans;
    }
};