class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        l=[]
        for i in range(1,n+1):
            l.append(i)
        i=0
        k=k-1
        while(len(l)!=1):
            i=(i+k)%len(l)
            l.remove(l[i])
        return l[0]