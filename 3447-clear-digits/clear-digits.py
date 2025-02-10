class Solution:
    def clearDigits(self, s: str) -> str:
        l=[]
        for i in s:
            if ord(i)>=ord("0") and ord(i)<=ord("9"):
                if len(l)!=0:
                    l.pop()
            else:
                l.append(i)
        return "".join(l)