class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        p=0
        k=0
        for i in range(1,n+1):
            if (m!=0 and i%m==0):
                p=p+i
            else:
                k+=i
        return k-p