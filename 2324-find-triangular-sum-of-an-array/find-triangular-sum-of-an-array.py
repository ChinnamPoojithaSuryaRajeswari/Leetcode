class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        i=0
        while(len(nums)>1):
            i=0
            while(i<len(nums)-1):
                nums[i]=(nums[i]+nums[i+1])%10
                i+=1
            nums.pop(len(nums)-1)
        return nums[0]