class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int k,bit=0,p=0,m=0;
        for(int i=left;i<=right;i++)
        {
            k=i;
            bit=0;
            p=0;
            while(k){
                                // cout<<k<<" gf ";
                if(k&1){
                    bit+=1;
                }
                k=k>>1;
            }
            for(int j=1;j<=sqrt(bit);j++)
            {
                if(bit%j==0)
                {
                    p+=1;
                }
            }
            if(p==1 and bit!=1)
            {
                m+=1;
                // cout<<i;
            }       
        }
        return m;
    }
};