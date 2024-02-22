class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        d={}
        di={}
        if n==1:
            return 1
        for i in trust:
            d[i[0]]=1
            if i[1] in di:
                di[i[1]]+=1
            else:
                di[i[1]]=1
        for i in range(1,n+1):
            if i not in d and i in di:
                if di[i]==n-1:
                    return i
        return -1