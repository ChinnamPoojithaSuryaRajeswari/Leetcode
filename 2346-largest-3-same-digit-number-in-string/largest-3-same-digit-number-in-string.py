class Solution(object):
    def largestGoodInteger(self, nums):
        """
        :type num: str
        :rtype: str
        """
        l=[]
        p=[]
        for i in range(len(nums)-2):
            for j in range(i,i+3):
                l.append(nums[j])
            if len(set(l))==1:
                p.append(nums[i:i+3])
            l=[]
        if len(p)==0:
            return ""
        else:
            return max(p)