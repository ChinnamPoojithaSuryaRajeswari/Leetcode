class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        d={}
        for i in words[0]:
            if i in d:
                d[i]+=1
            else:
                d[i]=1
        for i in words:
            d1={}
            for j in i:
                if j in d1:
                    d1[j]+=1
                else:
                    d1[j]=1
            for k in d:
                if k in d1 and d[k]!=0:
                    d[k]=min(d1[k],d[k])
                else:
                    d[k]=0
        l=[]
        for i in d:
            if d[i]!=0:
                for j in range(d[i]):
                    l.append(i)
        return l