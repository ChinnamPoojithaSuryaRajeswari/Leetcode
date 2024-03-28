class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        i=0
        l=[]
        c=0
        d={}
        while(i<len(nums)):
            l.append(nums[i])
            if nums[i] not in d:
                d[nums[i]]=1
            else:
                d[nums[i]]+=1
            if d[nums[i]]>k:
                if(c<len(l)-1):
                    c=len(l)-1
                while(l[0]!=nums[i]):
                    d[l[0]]-=1
                    l.remove(l[0])
                d[l[0]]-=1
                l.remove(l[0])
            i+=1
        if d[l[len(l)-1]]<=k:
            if(c<len(l)):
                    c=len(l)
        return c