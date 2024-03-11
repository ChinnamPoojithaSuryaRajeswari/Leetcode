class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        d={}
        for i in nums:
            if i not in d:
                d[i]=1
            else:
                d[i]+=1
        l=[]
        for i in nums:
            c=0
            for j in d:
                if i>j:
                    c+=d[j]
            l.append(c)
        return l