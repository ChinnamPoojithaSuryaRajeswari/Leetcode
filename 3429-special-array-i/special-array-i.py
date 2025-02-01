class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        n=len(nums)
        if n==1:
            return True
        else:
            for i in range(0,n-1):
                if nums[i]%2==0 and nums[i+1]%2==0:
                    return False
                if nums[i]%2!=0 and nums[i+1]%2!=0:
                    return False
            return True