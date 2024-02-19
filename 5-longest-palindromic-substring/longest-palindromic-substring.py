class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s)==1:
            return s
        i=1
        j=1
        pre=[]
        l=[]
        for i in range(1,len(s)-1):
            p=i-1
            j=i+1
            l.clear()
            l.append(s[i])
            if(len(l)>len(pre)):
                pre  = l.copy()
            while(p>=0 and j<len(s)):
                if(s[p]!=s[j]):
                    if(len(l)>len(pre)):
                        pre  = l.copy()
                    break
                else:
                    l.append(s[j])
                    l.insert(0,s[p])
                    p-=1
                    j+=1
            if(len(l)>len(pre)):
                    pre  = l.copy()
        preq=[]
        for i in  range(1,len(s)):
            p=i-1
            j=i
            if s[p]==s[j]:
                l.clear()
                l.append(s[p])
                l.append(s[j])
                if(len(l)>len(preq)):
                    preq  = l.copy()
                p-=1
                j+=1
                while(p>=0 and j<=len(s)-1):
                    if(s[p]!=s[j]):
                        if(len(l)>len(preq)):
                            preq  = l.copy()
                        break
                    else:
                        l.append(s[j])
                        l.insert(0,s[p])
                        p-=1
                        j+=1
                if(len(l)>len(preq)):
                    preq  = l.copy()
        if(len(pre)==0 and len(preq)==0):
            return s[0]
        if(len(preq)>len(pre)):
            return "".join(preq)
        return "".join(pre)
                    