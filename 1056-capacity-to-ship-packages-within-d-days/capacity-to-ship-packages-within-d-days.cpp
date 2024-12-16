class Solution {
public:
    int shipWithinDays(vector<int>& weights, int day) {
        int s=0,l=*max_element(weights.begin(),weights.end()),h;
        for(int i=0;i<weights.size();i++){
            s+=weights[i];
        }
        h=s;
        int mini = INT_MAX;
        while(l<=h){
            int m = (l+h)/2,days=0;
            int cnt=m;
            for(int i=0;i<weights.size();i++){
                if(cnt>=weights[i]){
                    cnt-=weights[i];
                }
                else{
                    days+=1;
                    cnt=m-weights[i];
                }
            }
            days+=1;
            if(days==day){
                h=m-1;
            }
            else if(days<day){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return l;
    }
};