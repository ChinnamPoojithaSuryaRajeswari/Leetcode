class Solution(object):
    def bagOfTokensScore(self, token, power):
        """
        :type tokens: List[int]
        :type power: int
        :rtype: int
        """
        i=0
        j=len(token)-1
        token.sort()
        score=0
        if(len(token)==0):
            return 0
        while(token[j]!=0):
            # print(score,power,token)
            if(token[i]<=power):
                power-=token[i]
                token[i]=0
                i+=1
                score+=1
            elif(score==0 and power<token[i]):
                return score
            elif(score>0 and i<j):
                power+=token[j]
                score-=1
                j-=1
            else:
                return score
        return score