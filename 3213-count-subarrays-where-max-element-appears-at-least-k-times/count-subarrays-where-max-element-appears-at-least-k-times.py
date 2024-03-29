class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        maxi=max(nums)
        max_count=0
        l=0
        res=0
        for i in range(len(nums)):
            if nums[i]==maxi:
                max_count+=1
            while(max_count>k or(l<=i and max_count==k and nums[l]!=maxi)):
                  if nums[l]==maxi:
                        max_count-=1
                  l+=1
            if max_count==k:
                  res+=l+1
        return res