class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        l=[]
        li=[]
        if(numRows==1):
            l.append(1)
            li.append(l)
            return li
        elif(numRows==2):
            l.append(1)
            li.append(l)
            l=[]
            l.append(1)
            l.append(1)
            li.append(l)
            return li
        li=[]
        l.append(1)
        li.append(l)
        l=[]
        l.append(1)
        l.append(1)
        li.append(l)
        numRows-=2
        p=1
        while(numRows):
            l=[]
            l.append(1)
            for i in range(len(li[p])-1):
                l.append(li[p][i]+li[p][i+1])
            l.append(1)
            li.append(l)
            numRows-=1
            p+=1
        return li