class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans=0;
        int minii = max(n-k,1);
        for(int i=minii ; i<= n+k;i++){
            if((n&i)==0)ans+=i;
        }
        return ans;
    }
};