class Solution:
    def equalFrequency(self, word: str) -> bool:
        d={}
        for i in word:
            if i in d:
                d[i]+=1
            else:
                d[i]=1
        if(set(d.values())=={1}):
            return True
        if(len(set(d.values()))==1 and len(d.values())==1):
            if(d.values()!=[1]):
                return True
        if(len(set(d.values()))==1):
            return False
        if(len(set(d.values()))==2):
            li=[]
            l=[]
            for i in set(d.values()):
                li.append(i)
            l=list(d.values())
            l.sort()
            if(l.count(li[0])>l.count(li[1])):
                l[len(l)-1]-=1
            elif(l.count(li[0])<l.count(li[1])):
                l[0]-=1
                if(l[0]==0):
                    l.remove(l[0])
            else:
                if(li[0]==1):
                    l[0]-=1
                    l.remove(l[0])
                else:
                    l[len(l)-1]-=1
            if(len(set(l))==1):
                return True
        return False