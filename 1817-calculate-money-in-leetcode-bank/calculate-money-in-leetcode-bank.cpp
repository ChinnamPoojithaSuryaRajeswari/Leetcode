class Solution {
public:
    int totalMoney(int n) {
        int k=n/7,i=0,l=n%7,s=0,p=0,j,q=0;
        while(q<k)
        {
            for(int j=q+1;j<=q+7;j++)
            {
                s=s+j;
            }
              q=q+1;
        }
        j=(p*7)+1;
        k=k+1;
        while(l)
        {
            l=l-1;
            s=s+k;
              k=k+1;
            j=j+1;
        }
        return s;
    }
};