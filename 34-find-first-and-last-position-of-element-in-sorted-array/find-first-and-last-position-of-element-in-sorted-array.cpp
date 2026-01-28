class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int l=0,h=arr.size()-1,left=-1,right=-1;
        bool flag=false;
        while(l<=h){
            int m = (l+h)/2;
            if(arr[m]>x){
                h = m-1;
            }
            if(arr[m]<=x){
                if(arr[m]<=x)l=m+1;
                if(arr[m]==x)left = m;
            }
            if(arr[m]==x){
                flag=true;
            }
        }
        l=0,h=arr.size()-1;
         while(l<=h){
            int m = (l+h)/2;
            if(arr[m]>=x){
                h = m-1;
                if(arr[m]==x)right = m;
            }
            if(arr[m]<x){
                 l=m+1;
            }
            if(arr[m]==x){
                flag=true;
            }
        }
        return {min(left,right),max(left,right)};
    }
};