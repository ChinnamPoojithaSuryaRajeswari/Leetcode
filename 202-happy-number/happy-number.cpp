class Solution {
public:
    bool isHappy(int n) {
        int ans = n;
        while(n>=10){
            ans  =  0;
            while(n){
                ans += (n%10)*(n%10);
                n=n/10;
            }
            n = ans;
        }
        return n==1 or n==7;
    }
};