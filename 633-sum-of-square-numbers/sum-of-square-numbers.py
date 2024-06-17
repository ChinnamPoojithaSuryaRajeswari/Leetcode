class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        l=[]
        for i in range(0,int(sqrt(c))+1):
            l.append(i)
        i=0
        j=len(l)-1
        while(i<=j):
            if(l[i]*l[i]+l[j]*l[j]>c):
                j-=1
            elif(l[i]*l[i]+l[j]*l[j]<c):
                i+=1
            else:
                return True
        return False