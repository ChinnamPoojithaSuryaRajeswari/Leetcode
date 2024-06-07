class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        d={}
        for i in dictionary:
            d[i]=1
        print(len(sentence))
        s=""
        l=[]
        for i in sentence:
            if i!=" ":
                s+=i
            else:
                l.append(s)
                s=""
        l.append(s)
        for i in range(len(l)):
            s=""
            for j in range(len(l[i])):
                s+=l[i][j]
                if(s in d):
                    l[i]=s
                    break
        return " ".join(l)