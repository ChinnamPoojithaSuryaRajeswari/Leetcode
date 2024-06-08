class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        d={}
        l=[]
        s=0
        for i in nums:
            s+=i
            l.append(s);
        c=0
        for i in nums:
            if(c==1 and i==0):
                return True
            if i == 0:
                c+=1
            else:
                c=0
        for i in range(len(l)):
            if l[i]%k in d and nums[i]!=0 and i!=0 and l[i-1]%k!=l[i]%k:
                return True
            if l[i]%k in d and nums[i-1]==0:
                return True
            if l[i]%k not in d:
                d[l[i]%k]=i
            # print(d)
        for i in range(1,len(l)):
            if l[i]%k==0:
                # print('sdfjlc')
                return True
        return False