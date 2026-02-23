class Solution {
public:
    int binaryGap(int n) {
        int ans=0,prev=-1,current=1;
        while(n){
            cout<<current<<" "<<prev<<endl;
            if((n&1)==1){
                if(prev==-1)prev = current;
                else{
                    ans = max(ans,current - prev);
                    prev= current;
                }
            }
            current++;
            n=n>>1;
        }
        return ans;
    }
};