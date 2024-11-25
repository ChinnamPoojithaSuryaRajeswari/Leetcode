class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        l=[]
        li=[]
        for i in strs:
            l.append(len(i))
        k=strs[l.index(min(l))]
        s=0
        for i in strs:
            for j in range(len(k)):
                if k[j]==i[j]:
                    s=s+1
                else:
                    break
            li.append(s)
            # print(s)
            s=0
        return k[:min(li):]