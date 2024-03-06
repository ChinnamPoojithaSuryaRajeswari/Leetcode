class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        d={}
        l=[]
        for i in nums:
            if i in d:
                d[i]+=1
            else:
                d[i]=1
        for i in d:
            if i-1 not in d:
                if i+1 not in d and d[i]==1:
                    l.append(i)
        return l