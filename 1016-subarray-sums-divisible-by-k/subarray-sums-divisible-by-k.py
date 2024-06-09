class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        d={}
        s=0
        pre=[]
        for i in nums:
            s+=i
            pre.append(s)
        c=0
        print(pre)
        for i in pre:
            if i%k==0:
                c+=1
            if i%k in d:
                c+=d[i%k]
            if i%k not in d:
                d[i%k]=1
            else:
                d[i%k]+=1
        return c