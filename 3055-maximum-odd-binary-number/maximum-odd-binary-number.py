class Solution(object):
    def maximumOddBinaryNumber(self, s):
        """
        :type s: str
        :rtype: str
        """
        l=[]
        for i in s:
            l.append(i)
        l.sort()
        l.reverse()
        print(l)
        t=-1
        for i in range(len(l)-1,-1,-1):
            if(l[i]=='1'):
                t = i
                break
                print(i)
        if(t==-1 or t==len(l)-1):
            return s
        l[t]='0'
        l[len(l)-1]='1'
        return "".join(l)
        