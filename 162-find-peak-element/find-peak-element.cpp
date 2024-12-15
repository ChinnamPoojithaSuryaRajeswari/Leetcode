class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int l=1,h=arr.size()-2;
        if(arr.size()==1){
            return 0;
        }
        if(arr[0]>arr[1]){
            return 0;
        }
        if(arr[arr.size()-1]>arr[arr.size()-2]){
            return arr.size()-1;
        }
        while(l<=h){
            int m = (l+h)/2;
            if(arr[m-1]<arr[m] && arr[m]>arr[m+1]){
                return m;
            }
            else if(arr[m]>arr[m-1]){
                l=m+1;
            }
            else if(arr[m]>arr[m+1]){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return -1;
    }
};