class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        s=0
        k=0
        if n<=0:
            return False
        while(n):
            if n&1:
                s=s+1
            k=k+1
            n=n>>1
        if(s==1 and k%2==1):
            return True
        else:
            return False