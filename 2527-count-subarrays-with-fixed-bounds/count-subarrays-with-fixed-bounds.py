class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        i=0
        while(i<len(nums)):
            badi=-1
            mini=-1
            ans=0
            maxi=-1
            n=len(nums)
            i=0
            while(i<n):
                if nums[i]<minK or nums[i]>maxK:
                    badi=i
                if nums[i]==minK:
                    mini=i
                if nums[i]==maxK:
                    maxi=i
                ans+=max(0,min(mini,maxi)-badi)
                i+=1
            return ans
            