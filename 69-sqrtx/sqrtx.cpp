class Solution {
public:
    int mySqrt(int x) {
        long long l=1,h=x;
        while(l<=h){
            long long m = (l+h)/2;
            if(m*m < x){
                l=m+1;
            }
            else if(m*m > x){
                h=m-1;
            }
            else{
                return m;
            }
        }
        return l-1;
    }
};