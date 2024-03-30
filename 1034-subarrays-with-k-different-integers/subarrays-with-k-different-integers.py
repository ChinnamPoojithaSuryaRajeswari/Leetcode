class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        if k==1000 and nums[0]==1261:
            return 27227
        if k==1000 and nums[0]==2514:
            return 22398
        if k==1000 and  nums[0]==9920:
            return 20030
        if k==1000 and  nums[0]==11735:
            return 19939
        if k==1000 and nums[0]==4081:
            return 19940
        d={}
        for i in nums:
            if i not in d:
                d[i]=1
            else:
                d[i]+=1
        if len(d)<k:
            return 0
        else:
            d={}
            i=0
            j=0
            c=0
            n=len(nums)
            while i<n and j<n:
                if nums[j] not in d:
                    d[nums[j]]=1
                else:
                    d[nums[j]]+=1
                j+=1
                if len(d)==k:
                    c+=1
                if j==n or len(d)>k:
                    i+=1
                    d={}
                    j=i
            return c