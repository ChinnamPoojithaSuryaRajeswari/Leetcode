class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int t) {
        int l=1,h=INT_MIN;
        sort(piles.begin(),piles.end());
        int s=0;
        for(int i=0;i<piles.size();i++){
            h=max(h,piles[i]);
        }
        while(l<=h){
            int m = (l+h)/2;
            long long res=0;
            for(int i=0;i<piles.size();i++){
                res+=(piles[i]/m);
                if(piles[i]%m){
                    res+=1;
                }
            }
            if(res>t){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return l;
    }
};