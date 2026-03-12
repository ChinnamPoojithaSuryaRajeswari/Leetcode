class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0, c = 0;
        if(n==0) return 1;
        while(n){
            if(n%2==0){
                ans += pow(2,c);
            }
            c+=1;
            n/=2;
        }
        return ans;
    }
};