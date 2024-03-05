class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        k = time%(n-1+n-1)
        print(k)
        if(k==0):
            return 1
        else:
            p=0
            i=1
            while(k):
                if(i==1):
                    p=0
                    i+=1
                elif(i==n):
                    p=1
                    i-=1
                else:
                    if p==1:
                        i-=1
                    else:
                        i+=1
                k-=1
            return i
                