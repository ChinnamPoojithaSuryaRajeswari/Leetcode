class Solution {
public:
    int countMonobit(int n) {
        if(n==0)return 1;
        if(n==1)return 2;
        int ans = 2;
        for(int i=2;i<=n;i++){
            if((i&(i+1))==0)ans++;
        }
        return ans;
    }
};