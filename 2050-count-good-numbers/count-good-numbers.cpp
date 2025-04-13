class Solution {
public:
    long long e=1e9+7;
    long long getPower(long long a,long long b){
        if(b==0){
            return 1;
        }
        long long res=getPower(a,b/2);
        if(b%2){
            return  (a%e * res%e * res%e)%e;
        }
        else{
            return (res%e * res%e)%e;
        }
    }
    int countGoodNumbers(long long n) {
        long long x=((n+1)/2);
        long long y=n/2;
        long long a=getPower(5,x);
        long long b=getPower(4,y);
        return (a%e * b%e)%e;
    }
};