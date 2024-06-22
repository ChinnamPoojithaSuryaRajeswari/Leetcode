class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        i=0
        res=0
        ans=0
        su=0
        for i in range(len(nums)):
            if(nums[i]%2==0):
                nums[i]=0
            else:
                nums[i]=1
        for i in range(len(nums)):
            su+=nums[i]
            nums[i]=su
        d={}
        i=0
        while(i<len(nums)):
            if nums[i] == k:  
                res += 1
            if (nums[i] - k) in d:
                res += d[nums[i]-k]
            if nums[i] in d:
                d[nums[i]]+=1
            else:
                d[nums[i]]=1
            i+=1
        return res