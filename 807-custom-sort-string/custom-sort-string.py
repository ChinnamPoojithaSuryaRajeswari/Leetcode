class Solution:
    def customSortString(self, order: str, s: str) -> str:
        d={}
        d1={}
        l=[]
        li=[]
        for i in order:
            d[i]=1
        for i in s:
            if i in d1:
                d1[i]+=1
            else:
                d1[i]=1
        for i in d:
            if i in d1:
                for j in range(d1[i]):
                    l.append(i)
        for i in d1:
            if i not in d:
                for j in range(d1[i]):
                    l.append(i)
        return "".join(l)