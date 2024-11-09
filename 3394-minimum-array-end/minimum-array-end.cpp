class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int>vec(64,0);
        int m = 0;
        n--;
        long long ans=0;
        while(x){
            if(x&1){
                vec[m]=1;
            }
            x=x>>1;
            m+=1;
        }
        m=0;
        while(n){
            while(vec[m]==1){
                m+=1;
            }
            n&1 ? vec[m]=1:vec[m]=0;
            m+=1;
            n=n>>1;
        }
        for(int i=0;i<64;i++){
            // cout<<vec[i]<<" ";
            ans=ans+(vec[i]*pow(2,i));
        }
        return ans;
    }
};