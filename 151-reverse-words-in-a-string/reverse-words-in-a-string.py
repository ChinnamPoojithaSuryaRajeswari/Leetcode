class Solution:
    def reverseWords(self, s: str) -> str:
        l=[]
        for i in s.split():
            l.append(i)
        i=0
        j=len(l)-1
        while(i<=j):
            temp=l[i]
            l[i]=l[j]
            l[j]=temp
            i+=1
            j-=1
        return " ".join(l)