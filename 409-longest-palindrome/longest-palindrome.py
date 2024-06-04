class Solution:
    def longestPalindrome(self, s: str) -> int:
        d={}
        c=0
        f=0
        for i in s:
            if i in d:
                d[i]+=1
            else:
                d[i]=1
        for i in d:
            if(d[i]%2==0):
                c+=d[i]
            else:
                f+=1
                c+=(d[i]-1)
        if f>0:
            return c+1
        return c