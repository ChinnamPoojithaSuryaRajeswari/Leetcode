class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        # k=n
        # while(n&(n-1)):
        #     n=n-1
        # h=0
        # while(n):
        #     n=n>>1
        #     h+=1
        # h=h-1
        # s=0
        # while(h>=0):
        #     s=s+(2**h)
        #     h=h-2
        # if(s==k):
        #     return True
        # else:
        #     return False
        if(n&1==1):
            q=0
            while(n):
                if(n&1 and q==0):
                    q+=1
                elif(n&1==0 and q==1):
                    q=q-1
                else:
                    return False
                n=n>>1
            return True
        else:
            q=0
            while(n):
                if(n&1 and q==-1):
                    q+=1
                elif(n&1==0 and q==0):
                    q=q-1
                else:
                    return False
                n=n>>1
            return True
            