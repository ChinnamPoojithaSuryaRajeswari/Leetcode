class Solution {
public:
    int minimumSum(int n, int k) {
        int ans = 0 , i= 1;
        while(n and i<=k/2){
            ans+=i;
            i++;
            n--;
        }
        i=k;
        while(n){
            n--;
            ans+=i;
            i++;
        }
        return ans;
    }
};