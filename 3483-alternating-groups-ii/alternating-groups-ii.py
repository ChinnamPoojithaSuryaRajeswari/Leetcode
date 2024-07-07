class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        l=[]
        for i in range(k-1):
            colors.append(colors[i])
        i=0
        c=0
        p=-1
        print(colors)
        print(len(colors))
        while(i<len(colors)):
            if(len(l)==0):
                l.append(colors[i])
            else:
                if(colors[i]!=l[len(l)-1]):
                    l.append(colors[i])
                else:
                    l.clear()
                    l.append(colors[i])
            if(len(l)==k):
                p=i
                break
            i+=1
        if(i==len(colors)):
            return 0
        if(len(l)==k):
            c+=1
        p+=1
        l.remove(l[0])
        while(p<len(colors)):
            if(len(l)==0):
                l.append(colors[p])
            else:
                if(colors[p]!=l[len(l)-1]):
                    l.append(colors[p])
                else:
                    l.clear()
                    l.append(colors[p])
            if(len(l)==k):
                c+=1
                l.remove(l[0])
            p+=1
        return c