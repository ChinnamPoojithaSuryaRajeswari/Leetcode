class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        s=0
        l=[]
        d={}
        for i in nums:
            s+=i
            l.append(s)
        count=0
        print(l)
        flag=0
        for i in l:
            if i==goal:
                count+=1
                if i - goal in d:
                    count+=d[i-goal]
                if i not in d:
                    d[i]=1
                else:
                    d[i]+=1
            else:
                if i-goal in d:
                    count+=d[i-goal]
                if i not in d:
                    d[i]=1
                else:
                    d[i]+=1
        return count