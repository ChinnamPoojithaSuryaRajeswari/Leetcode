class Solution {
public:
    bool isPowerOfTwo(int n) {
         if(n==1){
            return 1;
        }
        else if(n%2==1 or n==0)
        {
            return 0;
        }  
        n=n/2;
        return isPowerOfTwo(n);
    }
};