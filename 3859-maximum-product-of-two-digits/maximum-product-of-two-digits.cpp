class Solution {
public:
    int maxProduct(int n) {
        int maxxy1=0,maxxy2=0;
        while(n){
            if(n%10 >= maxxy1){
                maxxy2 = maxxy1;
                maxxy1 = n%10;
            }
            else if (n%10 > maxxy2) {
                maxxy2 = n%10;
            }
            n=n/10;
        }
        // cout<<maxxy1<<" "<<maxxy2<<endl;
        return maxxy1*maxxy2;
    }
};