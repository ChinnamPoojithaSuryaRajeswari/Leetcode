class Solution:
    def minimumLength(self, s: str) -> int:
        l=[]
        for i in s:
            l.append(i)
        i=0
        j=len(l)-1
        while(i<j):
            if(l[i]==l[j]):
                k = l[i]
                while(k==l[i]):
                    l.pop(i)
                    j-=1
                    if(len(l)==0):
                        return 0
                while(k==l[j]):
                    l.pop(j)
                    j-=1
                    if(len(l)==0):
                        return 0
            else:
                return len(l)
        return len(l)